#include <Python.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <math.h>
#include <algorithm>  


static PyObject * 
add (PyObject *self, PyObject *args){
    int x, y, result;

    if (! PyArg_Parse(args, "(ii)", &x, &y))
        return NULL;
    
    result = std::__gcd(x, y);
    
    return Py_BuildValue("i", result);

}
static PyObject *
message(PyObject *self, PyObject *args)
{
    char *fromPython, result[1024];
    if (! PyArg_Parse(args, "(s)", &fromPython))
        return NULL;

    else {
        strcpy(result, "Hello, ");
        strcat(result, fromPython);
        return Py_BuildValue("s", result);
    }
}

static PyMethodDef hello_methods[] = {
    {"add", add, METH_VARARGS, "func doc"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef hellomodule = {
    PyModuleDef_HEAD_INIT,
    "hello",
    "mod doc",
    -1,
    hello_methods,
};

PyMODINIT_FUNC
PyInit_hello()
{
    return PyModule_Create(&hellomodule);
}