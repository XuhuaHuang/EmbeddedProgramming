def intergrate(Function f, double a, double b, int N):
    cdef int i
    cdef double s, dx
    if f is None:
        raise ValueError("Function object f can not be found.")
    s = 0
    dx = (b - a) / N
    for i in range(N):
        s += f.evaluate(a + i * dx)
    return s * dx

print(intergrate(SinOfSquareFn(), 0, 1, 10000))