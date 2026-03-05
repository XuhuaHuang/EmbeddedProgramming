/**
 * @file large_integer_multiplication.c
 * @author Xuhua Huang
 * @brief Demonstrates large integer multiplication via recursive decomposition,
 * delegating sub-multiplications to a child process over a pair of pipes.
 *
 * Usage: ./large_mul <a> <b>   (both values must be in [1000, 9999])
 *
 * @version 0.1
 * @date 2026-02-20
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * @brief Signed 64-bit integer for intermediate values
 */
typedef long long ll_t;

/* A simple two-element message sent across either pipe. */
typedef struct {
  ll_t x;
  ll_t y;
} pair_t;

/**
 * @brief Write a pair_t struct atomically to a file descriptor.
 *
 * @param fd The file descriptor to write to.
 * @param p The pair_t struct to write.
 * @return int 0 on success, -1 on failure
 */
static int write_pair(int fd, pair_t p) {
  // `write` may not write all bytes in one call, but for small structs it is atomic on pipes.
  // it returns the number of bytes actually written, which may be less than sizeof(pair_t) if an error occurs.
  ssize_t n = write(fd, &p, sizeof(pair_t));
  if (n != (ssize_t)sizeof(pair_t)) {
    perror("write_pair: write");
    return -1;
  }
  return 0;
}

/**
 * @brief Read a pair_t struct atomically from a file descriptor.
 *
 * @param fd The file descriptor to read from.
 * @param p The pair_t struct to store the read values.
 * @return int 0 on success, -1 on failure
 */
static int read_pair(int fd, pair_t* p) {
  ssize_t n = read(fd, p, sizeof(pair_t));
  if (n != (ssize_t)sizeof(pair_t)) {
    perror("read_pair: read");
    return -1;
  }
  return 0;
}

/**
 * @brief Write a signed 64-bit integer atomically to a file descriptor.
 *
 * @param fd The file descriptor to write to.
 * @param v The value to write.
 * @return int 0 on success, -1 on failure
 */
static int write_ll(int fd, ll_t v) {
  ssize_t n = write(fd, &v, sizeof(ll_t));
  if (n != (ssize_t)sizeof(ll_t)) {
    perror("write_ll: write");
    return -1;
  }
  return 0;
}

/**
 * @brief Read a signed 64-bit integer atomically from a file descriptor.
 *
 * @param fd The file descriptor to read from.
 * @param v The point to store the read value in.
 * @return int 0 on success, -1 on failure
 */
static int read_ll(int fd, ll_t* v) {
  ssize_t n = read(fd, v, sizeof(ll_t));
  if (n != (ssize_t)sizeof(ll_t)) {
    perror("read_ll: read");
    return -1;
  }
  return 0;
}

/**
 * @brief The child waits for four pair_t messages, multiplies each pair, and
 * returns the ll_t result back to the parent.  After the fourth result it
 * closes its pipe ends and exits cleanly.
 *
 * @param pipe_in read-end of the parent to child pipe
 * @param pipe_out write-end of the child to parent pipe
 */
static void run_child(int pipe_in, int pipe_out) {
  for (int i = 0; i < 4; ++i) {
    pair_t operands;
    if (read_pair(pipe_in, &operands) != 0) {
      fprintf(stderr, "child: failed to read operands (round %d)\n", i + 1);
      exit(EXIT_FAILURE);
    }

    ll_t product = operands.x * operands.y;

    printf("[child]  round %d: %lld * %lld = %lld\n", i + 1, operands.x, operands.y, product);
    fflush(stdout);

    if (write_ll(pipe_out, product) != 0) {
      fprintf(stderr, "child: failed to write result (round %d)\n", i + 1);
      exit(EXIT_FAILURE);
    }
  }

  close(pipe_in);
  close(pipe_out);
  exit(EXIT_SUCCESS);
}

static ll_t send_and_receive(int pipe_out, int pipe_in, ll_t x, ll_t y) {
  pair_t job = {x, y};
  if (write_pair(pipe_out, job) != 0) {
    fprintf(stderr, "parent: failed to send job (%lld, %lld)\n", x, y);
    exit(EXIT_FAILURE);
  }

  ll_t result = 0;
  if (read_ll(pipe_in, &result) != 0) {
    fprintf(stderr, "parent: failed to read result for (%lld, %lld)\n", x, y);
    exit(EXIT_FAILURE);
  }
  return result;
}

int main(int argc, char* argv[]) {
  /* --- Argument validation ------------------------------------------ */
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <a> <b>\n", argv[0]);
    fprintf(stderr, "  Both arguments must be integers in the range [1000, 9999].\n");
    return EXIT_FAILURE;
  }

  char *end_ptr_a = NULL, *end_ptr_b = NULL;
  ll_t  a = strtoll(argv[1], &end_ptr_a, 10);
  ll_t  b = strtoll(argv[2], &end_ptr_b, 10);

  if (*end_ptr_a != '\0' || *end_ptr_b != '\0') {
    fprintf(stderr, "Error: non-numeric input detected.\n");
    return EXIT_FAILURE;
  }
  if (a < 1000 || a > 9999 || b < 1000 || b > 9999) {
    fprintf(stderr, "Error: both values must be 4-digit integers (1000-9999).\n");
    return EXIT_FAILURE;
  }

  /* --- Decompose a and b -------------------------------------------- */
  ll_t a1 = a / 100; /* high two digits of a */
  ll_t a2 = a % 100; /* low  two digits of a */
  ll_t b1 = b / 100; /* high two digits of b */
  ll_t b2 = b % 100; /* low  two digits of b */

  printf("[parent] a=%lld  =>  a1=%lld, a2=%lld\n", a, a1, a2);
  printf("[parent] b=%lld  =>  b1=%lld, b2=%lld\n", b, b1, b2);
  fflush(stdout);

  /* --- Establish pipes ----------------------------------------------- */
  int parent_to_child[2]; /* parent writes, child reads  */
  int child_to_parent[2]; /* child  writes, parent reads */

  if (pipe(parent_to_child) == -1 || pipe(child_to_parent) == -1) {
    perror("pipe");
    return EXIT_FAILURE;
  }

  /* --- Fork ---------------------------------------------------------- */
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    return EXIT_FAILURE;
  }

  if (pid == 0) {
    /* ---- Child ---- */
    close(parent_to_child[1]); /* child does not write to this pipe  */
    close(child_to_parent[0]); /* child does not read  from this pipe */

    run_child(parent_to_child[0], child_to_parent[1]);
    /* run_child never returns */
  }

  /* ---- Parent ---- */
  close(parent_to_child[0]); /* parent does not read from this pipe  */
  close(child_to_parent[1]); /* parent does not write to this pipe   */

  int p_write = parent_to_child[1];
  int p_read  = child_to_parent[0];

  /* Round 1: A = a1 * b1  =>  X = A * 10^4 */
  ll_t A = send_and_receive(p_write, p_read, a1, b1);
  ll_t X = A * 10000LL;
  printf("[parent] A = a1*b1 = %lld  =>  X = A*10^4 = %lld\n", A, X);

  /* Round 2: B = a2 * b1 */
  ll_t B = send_and_receive(p_write, p_read, a2, b1);
  printf("[parent] B = a2*b1 = %lld\n", B);

  /* Round 3: C = a1 * b2  =>  Y = (B + C) * 10^2 */
  ll_t C = send_and_receive(p_write, p_read, a1, b2);
  ll_t Y = (B + C) * 100LL;
  printf("[parent] C = a1*b2 = %lld  =>  Y = (B+C)*10^2 = %lld\n", C, Y);

  /* Round 4: D = a2 * b2  =>  Z = D * 10^0 */
  ll_t D = send_and_receive(p_write, p_read, a2, b2);
  ll_t Z = D;
  printf("[parent] D = a2*b2 = %lld  =>  Z = D = %lld\n", D, Z);

  /* --- Close pipe ends and reap child -------------------------------- */
  close(p_write);
  close(p_read);

  int status = 0;
  waitpid(pid, &status, 0);
  if (!WIFEXITED(status) || WEXITSTATUS(status) != EXIT_SUCCESS) {
    fprintf(stderr, "Warning: child process did not exit cleanly.\n");
  }

  /* --- Final computation -------------------------------------------- */
  ll_t result = X + Y + Z;

  printf("\n[parent] X + Y + Z = %lld + %lld + %lld = %lld\n", X, Y, Z, result);
  printf("[parent] Verification: %lld * %lld = %lld\n", a, b, a * b);

  return EXIT_SUCCESS;
}
