/**
Author : @bhargavpanth
**/ 


#include <Python.h>

// Python Exception object
static PyObject extractError*;

static PyObject* extract(PyObject* self, PyObject *args) {

	const char* fname;

	int sts = 0;

	if (!PyArg_ParseTuple(args, "s", &fname)) 
	{
		return NULL;
	}

	if (strcmp(fname, "err") == 0)
	{
		PyErr_SetString(extractError, "Argument not passed. Method expects file path argument");
		return NULL;
	}
	else
	{
		// Check if the file path exists
		printf("%s\n", &fname);
		sts = 21;

	} 

	return Py_BuildValue("i", sts);

}

/* Sample method to understand parsing double / int */

static PyObject* add(PyObject* self, PyObject *args) {

	double num_one, num_two;

	double sts = 0;

	if (!PyArg_ParseTuple(args, "dd", &num_one, &num_two))
	{
		return NULL;
	}

	sts = num_one + num_two;
	
	printf("%f\n", &sts);
	
	return Py_BuildValue("f", sts);
}


/*
At the end creating all functions - a function table is required to be created
set of method defenition -> function names
*/

static PyMethodDef extract_methods[] = {
	// "Python name",	C Funciton name,	argument_presentation,	description
	{"extract", extract, METH_VARARGS, "extract a file content by passing the file path"},
	
	{"add", add, METH_VARARGS,"sample test file to add two numbers"},
	/* Sentinal */
	{NULL, NULL, 0, NULL}
};


PyMODINIT_FUNC initextract(void)
{
	PyObject *m;
	
	m = Py_InitModule("extract", extract_methods);

	if (m == NULL)
	{
		return;
	}

	extractError = PyErr_NewException("extract.error", NULL, NULL);

	Py_INCREF(extractError);

	PyModule_AddObject(m, "error", extractError);
}