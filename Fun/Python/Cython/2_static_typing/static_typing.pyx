'''
Pure Python code
def f(x):
    return x ** 2 - x


def integrate_f(a, b, N):
    s = 0
    dx = (b - a) / N
    for i in range(N):
        s += f(a + i * dx)
    return s * dx
'''


'''
Add data types to variables
def f(double x):
    return x ** 2 - x
'''


def integrate_f(double a, double b, int N):
    cdef int i
    cdef double s, dx
    s = 0
    dx = (b - a) / N
    for i in range(N):
        s += f(a + i * dx)
    return s * dx


''' Declare a C-style function '''
cdef double f(double x) except? -2:
  return x ** 2 - x
