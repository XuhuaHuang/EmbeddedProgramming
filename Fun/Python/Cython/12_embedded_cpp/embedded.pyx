# embedded.pyx

# The following two lines are for test purposed only, please ignore them.
# distutils: sources = embedded_main.c
# tag: py3only

TEXT_TO_SAY = 'Hello from Python!'

'''
This function is prefixed with a public keyword to export it
as a linker symbol that can be ued by another C file
'''
cdef public int say_hello_from_python() except -1:
    print(TEXT_TO_SAY)
    return 0

