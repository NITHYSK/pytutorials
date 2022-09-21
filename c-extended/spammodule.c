#define PY_SSIZE_T_CLEAN
#include "spammodule.h"
#include <Python.h>	/* Python APIの取り込み */
#include <stdio.h>

static PyObject *
spam_system(PyObject *self, PyObject *args)
{
	const char *command;
	int sts;

	if (!PyArg_ParseTuple(args, "s", &command))
		return NULL;
	sts = system(command);
	return PyLong_FromLong(sts);
}

static PyObject *
spam_hoge(PyObject *self, PyObject *args)
{
	const char *text;
	if(!PyArg_ParseTuple(args, "s", &text))
		return NULL;
	return PyLong_FromLong(fprintf(stdout, "%s", text));
}

/* メソッドの定義 */
static PyMethodDef SpamMethods[] = {
	{"spam_system", (PyCFunction)spam_system, METH_VARARGS, "spam1: spam_system"},
	{"spam_hoge", (PyCFunction)spam_hoge, METH_VARARGS, "spam2: spam_hoge"},
	{NULL, NULL, 0, NULL}
};

/* モジュールの定義 */
static struct PyModuleDef spammodule = {
	PyModuleDef_HEAD_INIT,
	"spam",
	NULL,
	-1,
	SpamMethods
};

/* メソッドの初期化 */
PyMODINIT_FUNC PyInit_spam (void)
{
	return PyModule_Create(&spammodule);
}
