from distutils.core import setup, Extension

module = Extension(
	'extract',
	include_dirs = ['/usr/local/include/'],
	libraries = ['pthread'],
	sources = ['./lib/extractmodule.c']
	)


setup(
	name='extract',
	verison='0.1',
	description='This package allows user to extract a combined linked dataset',
	author='Bhargav Panth',
	url='https://github.com/bhargavpanth/LinkedData-Extractor',
	ext_modules=[module]
	)