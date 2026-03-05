/**
 * @file large_integer_multiplication.c
 * @author Xuhua Huang
 * @brief Demonstrates large integer multiplication via recursive decomposition,
 * delegating sub-multiplications to a child process over a pair of pipes.
 *
 * Usage: ./large_mul <a> <b> (both values must be in [1000, 9999])
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
 * @brief Signed 64-bit integer used for all intermediate and final values.
 */
typedef long long ll_t;

static inline void print_calc(const char* label) {
  printf("\n");
  printf("#################\n");
  printf("# Calculating %s #\n", label);
  printf("#################\n");
  return;
}

/**
 * @brief Write a single ll_t value atomically to a file descriptor.
 *
 * @param fd  Destination file descriptor.
 * @param v   Value to transmit.
 * @return int 0 on success, -1 on failure.
 */
static inline int write_ll(int fd, ll_t v) {
  ssize_t n = write(fd, &v, sizeof(ll_t));
  if (n != (ssize_t)sizeof(ll_t)) {
    perror("write_ll: write");
    return -1;
  }
  return 0;
}

/**
 * @brief Read a single ll_t value atomically from a file descriptor.
 *
 * @param fd  Source file descriptor.
 * @param v   Pointer to store the received value.
 * @return int 0 on success, -1 on failure.
 */
static inline int read_ll(int fd, ll_t* v) {
  ssize_t n = read(fd, v, sizeof(ll_t));
  if (n != (ssize_t)sizeof(ll_t)) {
    perror("read_ll: read");
    return -1;
  }
  return 0;
}

/**
 * @brief Child event loop: receives two operands individually, multiplies
 * them, and returns the product.  Repeats for @p rounds iterations before
 * closing its pipe ends and exiting cleanly.
 *
 * @param pipe_in   Read-end of the parent-to-child pipe.
 * @param pipe_out  Write-end of the child-to-parent pipe.
 * @param rounds    Number of multiplication jobs to process.
 */
static void run_child(int pipe_in, int pipe_out, int rounds) {
  pid_t curr_pid   = getpid();
  pid_t parent_pid = getppid();

  for (int i = 0; i < rounds; ++i) {
    ll_t x = 0, y = 0;

    if (read_ll(pipe_in, &x) != 0) {
      fprintf(
        stderr, "Child (PID %d, PPID %d): failed to read first operand (round %d)\n", curr_pid, parent_pid, i + 1
      );
      exit(EXIT_FAILURE);
    }
    printf("Child (PID %d, PPID %d): Received %lld from parent\n", curr_pid, parent_pid, x);
    fflush(stdout);

    if (read_ll(pipe_in, &y) != 0) {
      fprintf(
        stderr, "Child (PID %d, PPID %d): failed to read second operand (round %d)\n", curr_pid, parent_pid, i + 1
      );
      exit(EXIT_FAILURE);
    }
    printf("Child (PID %d, PPID %d): Received %lld from parent\n", curr_pid, parent_pid, y);
    fflush(stdout);

    ll_t product = x * y;
    printf("Child (PID %d, PPID %d): Sending %lld to parent\n", curr_pid, parent_pid, product);
    fflush(stdout);

    if (write_ll(pipe_out, product) != 0) {
      fprintf(stderr, "Child (PID %d PPID %d): failed to write result (round %d)\n", curr_pid, parent_pid, i + 1);
      exit(EXIT_FAILURE);
    }
  }

  close(pipe_in);
  close(pipe_out);
  exit(EXIT_SUCCESS);
}

/**
 * @brief Send two operands to the child individually and await the product.
 *
 * Each operand is transmitted as a distinct ll_t write so the child can
 * log its receipt of each value independently, matching the expected output
 * protocol.
 *
 * @param p_write    Write-end of the parent-to-child pipe.
 * @param p_read     Read-end of the child-to-parent pipe.
 * @param x          First operand.
 * @param y          Second operand.
 * @param parent_pid PID of the parent process, for logging.
 * @return ll_t      The product returned by the child.
 */
static ll_t send_and_receive(int p_write, int p_read, ll_t x, ll_t y, pid_t parent_pid) {
  printf("Parent (PID %d): Sending %lld to child\n", parent_pid, x);
  fflush(stdout);
  if (write_ll(p_write, x) != 0) {
    fprintf(stderr, "Parent (PID %d): failed to send %lld\n", parent_pid, x);
    exit(EXIT_FAILURE);
  }

  printf("Parent (PID %d): Sending %lld to child\n", parent_pid, y);
  fflush(stdout);
  if (write_ll(p_write, y) != 0) {
    fprintf(stderr, "Parent (PID %d): failed to send %lld\n", parent_pid, y);
    exit(EXIT_FAILURE);
  }

  ll_t result = 0;
  if (read_ll(p_read, &result) != 0) {
    fprintf(stderr, "Parent (PID %d): failed to read result for (%lld, %lld)\n", parent_pid, x, y);
    exit(EXIT_FAILURE);
  }
  printf("Parent (PID %d): Received %lld from child\n", parent_pid, result);
  fflush(stdout);

  return result;
}

int main(int argc, char* argv[]) {
  /* Argument validation */
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

  printf("Your integers are %lld %lld\n", a, b);
  fflush(stdout);

  /* Decompose a and b */
  ll_t a1 = a / 100; // first two digits of a, integer division truncates
  ll_t a2 = a % 100; // last two digits of a
  ll_t b1 = b / 100; // firsttwo digits of b
  ll_t b2 = b % 100; // last two digits of b

  /* Establish pipes */
  int parent_to_child[2]; /* parent writes, child reads  */
  int child_to_parent[2]; /* child  writes, parent reads */

  if (pipe(parent_to_child) == -1 || pipe(child_to_parent) == -1) {
    perror("pipe");
    return EXIT_FAILURE;
  }

  /* Fork */
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    return EXIT_FAILURE;
  }

  /* Most importanat part of the program */
  // Identify the child process and run the child event loop
  if (pid == 0) {
    /* Child */
    // Close unused pipe ends in the child thread for hygiene and to avoid accidental misuse.
    close(parent_to_child[1]); /* child does not write to this pipe  */
    close(child_to_parent[0]); /* child does not read  from this pipe */

    run_child(parent_to_child[0], child_to_parent[1], /* rounds = */ 4);
    /* run_child never returns */
  }

  /* Parent */
  pid_t parent_pid = getpid();

  close(parent_to_child[0]); /* parent does not read from this pipe  */
  close(child_to_parent[1]); /* parent does not write to this pipe   */

  int p_write = parent_to_child[1];
  int p_read  = child_to_parent[0];

  printf("Parent (PID %d): created child (PID %d)\n", parent_pid, pid);
  fflush(stdout);

  /* Round 1: X = (a1 * b1) * 10^4 */
  print_calc("X");
  fflush(stdout);

  ll_t A = send_and_receive(p_write, p_read, a1, b1, parent_pid);
  ll_t X = A * 10000LL;

  /* Round 2 & 3: Y = (a1*b2 + a2*b1) * 10^2 */
  print_calc("Y");
  fflush(stdout);

  ll_t B = send_and_receive(p_write, p_read, a1, b2, parent_pid);
  ll_t C = send_and_receive(p_write, p_read, a2, b1, parent_pid);
  ll_t Y = (B + C) * 100LL;

  /* Round 4: Z = a2 * b2 */
  print_calc("Z");
  fflush(stdout);

  ll_t D = send_and_receive(p_write, p_read, a2, b2, parent_pid);
  ll_t Z = D;

  /* Close pipe ends and reap child */
  close(p_write);
  close(p_read);

  int status = 0;
  waitpid(pid, &status, 0);
  if (!WIFEXITED(status) || WEXITSTATUS(status) != EXIT_SUCCESS) {
    fprintf(stderr, "Warning: child process did not exit cleanly.\n");
  }

  /* Final result */
  ll_t result = X + Y + Z;

  printf("\n%lld * %lld == %lld + %lld + %lld == %lld\n", a, b, X, Y, Z, result);

  return EXIT_SUCCESS;
}
