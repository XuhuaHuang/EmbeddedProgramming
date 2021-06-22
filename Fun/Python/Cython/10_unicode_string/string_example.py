'''
Contains source code to test the functionality of the extension
'''

from c_func cimport c_call_returning_c_string()
from c_func cimport cimport get_c_string()

import icecream


def main():
    # retrieve string content from module
    cdef char* demo_c_string = c_call_returning_c_string()
    
    if demo_c_string is NULL:
        raise TypeError('Failed to Read String Content')
    else:
        cdef bytes py_string = c_string
        ic(py_string)
        
        
if __name__ == '__main__':
    main()