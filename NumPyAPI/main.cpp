/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   January 07, 2023
 *********************************************************************/

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION

#include <iostream>
#include <cstdlib>

#include <Python.h>
#include <numpy/arrayobject.h>

auto main(int argc, char* argv[]) -> int {
    // Initialize the Python interpreter
    Py_Initialize();

    // Import the NumPy module
    PyObject* numpy = PyImport_ImportModule("numpy");

    // Convert a Python list to a NumPy array
    PyObject* list = PyList_New(3);
    PyList_SetItem(list, 0, PyLong_FromLong(1));
    PyList_SetItem(list, 1, PyLong_FromLong(2));
    PyList_SetItem(list, 2, PyLong_FromLong(3));
    PyObject* array = PyObject_CallMethod(numpy, "array", "O", list);

    // Get the data type of the array
    PyObject* dtype = PyObject_GetAttrString(array, "dtype");
    const char* str = PyUnicode_AsUTF8(dtype);
    printf("Data type: %s\n", str);

    // Get the shape of the array
    PyObject* shape = PyObject_GetAttrString(array, "shape");
    Py_ssize_t len = PyTuple_Size(shape);
    printf("Shape: (%ld", PyLong_AsLong(PyTuple_GetItem(shape, 0)));
    for (int i = 1; i < len; i++) {
        printf(", %ld", PyLong_AsLong(PyTuple_GetItem(shape, i)));
    }
    printf(")\n");

    // Access the elements of the array
    // for (int i = 0; i < PyArray_SIZE(array); i++) {
    //    printf("%ld ", PyLong_AsLong(PyArray_GetItem(array, i)));
    // }
    // printf("\n");

    // Clean up
    Py_DECREF(array);
    Py_DECREF(numpy);
    Py_Finalize();

    return EXIT_SUCCESS;
}
