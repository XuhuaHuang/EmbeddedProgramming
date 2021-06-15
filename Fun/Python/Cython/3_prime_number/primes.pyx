from __future__ import print_function


''' Routine looking for prime numbers '''
def primes(int nb_primes):
    cdef int n, i, len_p
    cdef int p[1000]
    
    # limit the element count in the list
    if nb_primes > 1000:
        nb_primes = 1000

    len_p = 0  # current number of elements in p
    n = 2
    while len_p < nb_primes:
        # determine if n is a prime number
        for i in p[:len_p]:
            if n % i == 0:
                break

        # if not break occurred in the loop, we have a prime
        else:
            p[len_p] = n
            len_p += 1
        n += 1

    # return the result in a python list
    result_as_list  = [prime for prime in p[:len_p]]
    print(result_as_list)
    return result_as_list