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
		printf("Reading %s\n", fname);
		/* read and extract file content */
		read_from_file_open(fname, 250000);

		sts = 21;

	} 

	return Py_BuildValue("i", sts);

}


int read_from_file_open(char *filename,size_t size)
{
	int fd;

	long *buffer = (long*)malloc(size * sizeof(long));

	fd = open(filename);

	if (fd == -1)
	{
		printf("\nFile Open Unsuccessful\n");
		exit (0);;
	}

	off_t chunk=0;
	
	lseek(fd,0,SEEK_SET);
	
	printf("\nCurrent Position%d\n",lseek(fd,size,SEEK_SET));
	
	while ( chunk < size )
	{
		printf ("the size of chunk read is  %d\n",chunk);
   
   		size_t readnow;
   		
   		readnow=read(fd,((char *)buffer)+chunk,1048576);
		
		if (readnow < 0 )
     	{
			printf("\nRead Unsuccessful\n");
			
			free (buffer);
			
			close (fd);
			
			return 0;
		}

		chunk=chunk+readnow;
  }

  printf("\nRead Successful\n");

  free(buffer);

  close(fd);

  return 1;
}


/*
	function table
	set of method defenition -> function names
*/

static PyMethodDef extract_methods[] = {
	// "Python name",	C Funciton name,	argument_presentation,	description
	{"extract", LDExtract, METH_VARARGS, "extract a file content by passing the file path"},
	
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