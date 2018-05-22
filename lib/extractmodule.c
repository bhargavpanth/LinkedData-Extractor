/**
Author : @bhargavpanth

**/ 


#include <Python.h>

// Python Exception object
static PyObject *extractError;

static PyObject* LDExtract(PyObject* self, PyObject *args) {

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
		printf("%s\n", fname);
		/* read and extract file content */

		sts = 21;

	} 

	return Py_BuildValue("i", sts);

}


/*
	function table
	set of method defenition -> function names
*/

static PyMethodDef extract_methods[] = {
	// "Python name",	C Funciton name,	argument_presentation,	description
	{"extract", extract, METH_VARARGS, "extract a file content by passing the file path"},
	
	/* Sentinal */
	{NULL, NULL, 0, NULL}
};


/*
	
*/

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