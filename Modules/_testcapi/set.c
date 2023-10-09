#include <stddef.h>               // ptrdiff_t

#include "parts.h"
#include "util.h"

static PyObject *
set_check(PyObject *self, PyObject *obj)
{
    NULLABLE(obj);
    RETURN_INT(PySet_Check(obj));
}

static PyObject *
set_checkexact(PyObject *self, PyObject *obj)
{
    NULLABLE(obj);
    RETURN_INT(PySet_CheckExact(obj));
}

static PyObject *
frozenset_check(PyObject *self, PyObject *obj)
{
    NULLABLE(obj);
    RETURN_INT(PyFrozenSet_Check(obj));
}

static PyObject *
frozenset_checkexact(PyObject *self, PyObject *obj)
{
    NULLABLE(obj);
    RETURN_INT(PyFrozenSet_CheckExact(obj));
}

static PyObject *
anyset_check(PyObject *self, PyObject *obj)
{
    NULLABLE(obj);
    RETURN_INT(PyAnySet_Check(obj));
}

static PyObject *
anyset_checkexact(PyObject *self, PyObject *obj)
{
    NULLABLE(obj);
    RETURN_INT(PyAnySet_CheckExact(obj));
}

static PyObject *
set_new(PyObject *self, PyObject *args)
{
    PyObject *iterable = NULL;
    if (!PyArg_ParseTuple(args, "|O", &iterable)) {
        return NULL;
    }
    return PySet_New(iterable);
}

static PyObject *
frozenset_new(PyObject *self, PyObject *args)
{
    PyObject *iterable = NULL;
    if (!PyArg_ParseTuple(args, "|O", &iterable)) {
        return NULL;
    }
    return PyFrozenSet_New(iterable);
}

static PyObject *
set_size(PyObject *self, PyObject *obj)
{
    NULLABLE(obj);
    RETURN_SIZE(PySet_Size(obj));
}

static PyObject *
set_get_size(PyObject *self, PyObject *obj)
{
    NULLABLE(obj);
    RETURN_SIZE(PySet_GET_SIZE(obj));
}

static PyObject *
set_contains(PyObject *self, PyObject *args)
{
    PyObject *obj, *item;
    if (!PyArg_ParseTuple(args, "OO", &obj, &item)) {
        return NULL;
    }
    NULLABLE(obj);
    NULLABLE(item);
    RETURN_INT(PySet_Contains(obj, item));
}

static PyObject *
set_add(PyObject *self, PyObject *args)
{
    PyObject *obj, *item;
    if (!PyArg_ParseTuple(args, "OO", &obj, &item)) {
        return NULL;
    }
    NULLABLE(obj);
    NULLABLE(item);
    RETURN_INT(PySet_Add(obj, item));
}

static PyObject *
set_discard(PyObject *self, PyObject *args)
{
    PyObject *obj, *item;
    if (!PyArg_ParseTuple(args, "OO", &obj, &item)) {
        return NULL;
    }
    NULLABLE(obj);
    NULLABLE(item);
    RETURN_INT(PySet_Discard(obj, item));
}

static PyObject *
set_pop(PyObject *self, PyObject *obj)
{
    NULLABLE(obj);
    return PySet_Pop(obj);
}

static PyObject *
set_clear(PyObject *self, PyObject *obj)
{
    NULLABLE(obj);
    RETURN_INT(PySet_Clear(obj));
}

static PyMethodDef test_methods[] = {
    {"set_check", set_check, METH_O},
    {"set_checkexact", set_checkexact, METH_O},
    {"frozenset_check", frozenset_check, METH_O},
    {"frozenset_checkexact", frozenset_checkexact, METH_O},
    {"anyset_check", anyset_check, METH_O},
    {"anyset_checkexact", anyset_checkexact, METH_O},

    {"set_new", set_new, METH_VARARGS},
    {"frozenset_new", frozenset_new, METH_VARARGS},

    {"set_size", set_size, METH_O},
    {"set_get_size", set_get_size, METH_O},
    {"set_contains", set_contains, METH_VARARGS},
    {"set_add", set_add, METH_VARARGS},
    {"set_discard", set_discard, METH_VARARGS},
    {"set_pop", set_pop, METH_O},
    {"set_clear", set_clear, METH_O},

    {NULL},
};

int
_PyTestCapi_Init_Set(PyObject *m)
{
    if (PyModule_AddFunctions(m, test_methods) < 0) {
        return -1;
    }

    return 0;
}
