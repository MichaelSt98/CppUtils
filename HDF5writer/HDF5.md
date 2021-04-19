# HDF5

The **H**ierarchical **D**ata **F**ormat (**HDF**) is designed to store and organize large amounts of data. HDF5 is a trurly hiararchical, filesystem-like data format, which can be accessed using the POSIX-like syntax *path/to/resource*. Metadata is stored in the form of user-defined, named attributes attached to groups and datasets.

The file structure of HDF5 includes two major types of objects:

* **Datasets**: mutidimensional arrays of a homogeneous type
* **Groups**: container structures, holding datasets and other groups

## Links

* [Wikipedia: Hierarchical Data Format](https://en.wikipedia.org/wiki/Hierarchical_Data_Format)
* [HDF5 - The HDF Group](https://support.hdfgroup.org/HDF5/)
* [HDF5 documents and links](https://support.hdfgroup.org/HDF5/doc/index.html)
* [The HDF5 Library & File Format](https://www.hdfgroup.org/solutions/hdf5/)
* [HDF5 File Format Specification](https://support.hdfgroup.org/HDF5/doc/H5.format.html)
* [HDF5 User Guide](https://support.hdfgroup.org/HDF5/doc/UG/HDF5_Users_Guide-Responsive%20HTML5/index.html#t=HDF5_Users_Guide%2FHDF5_UG_Title%2FHDF5_UG_Title.htm)
* [HDF5: API Specification Reference Manual](https://support.hdfgroup.org/HDF5/doc/RM/RM_H5Front.html)

* [**Download:** source code](https://www.hdfgroup.org/downloads/hdf5/source-code/)

## Parallel HDF5

See [MPI_ParallelFileIO summary](resources/MPI_ParallelFileIO.md)

* [Parallel HDF5 - The HDF Group](https://support.hdfgroup.org/HDF5/PHDF5/)

## API

### C

* [GitHub: Implementation](https://github.com/HDFGroup/hdf5)

|HDF5 C APIs                       | Link              | Description                      |
|----------------------------------|-------------------|----------------------------------|   
|General-purpose interface 			| [Library Functions](https://support.hdfgroup.org/HDF5/doc/RM/RM_H5.html) | The general-purpose H5 functions |
|Attribute Interface (**H5A**)    	| [Attribute Interface](https://support.hdfgroup.org/HDF5/doc/RM/RM_H5A.html) | The H5A API for attributes |
|Datasets Interface (**H5D**)     	| [Dataset Interface](https://support.hdfgroup.org/HDF5/doc/RM/RM_H5D.html) | The H5D API for manipulating scientific datasets|
|Error Interface (**H5E**)       	| [Error Interface](https://support.hdfgroup.org/HDF5/doc/RM/RM_H5E.html) | The H5E API for error handling |
|File Interface (**H5F**)         	| [File Interface](https://support.hdfgroup.org/HDF5/doc/RM/RM_H5F.html) | The H5F API for accessing HDF5 files |
|Group Interface (**H5G**)        	| [Group Interface](https://support.hdfgroup.org/HDF5/doc/RM/RM_H5G.html) | The H5G API for creating physical groups of objects on disk |
|Identifier Interface (**H5I**)   	| [Identifier Interface](https://support.hdfgroup.org/HDF5/doc/RM/RM_H5I.html) | The H5I API for working with object identifiers |
|Property List Interface (**H5P**)	| [Property List Interface](https://support.hdfgroup.org/HDF5/doc/RM/RM_H5P.html) | The H5P API for manipulating object property lists |
|Plugin Interface (**H5PL**)	| [Plugin Interface](https://support.hdfgroup.org/HDF5/doc/RM/RM_H5PL.html) | The H5PL API for dynamically loaded plugins |
|Reference Interface (**H5R**)	| [Reference Interface](https://support.hdfgroup.org/HDF5/doc/RM/RM_H5R.html) | The H5R API for references |
|Dataspace Interface (**H5S**)    	| [Dataspace Interface](https://support.hdfgroup.org/HDF5/doc/RM/RM_H5S.html) | The H5S API for defining dataset dataspace |
|Datatype Interface (**H5T**)     	| [Datatype Interface](https://support.hdfgroup.org/HDF5/doc/RM/RM_H5T.html) | The H5T API for defining dataset element information |
  
  
### C++

* [The HDF5 C++ API](https://support.hdfgroup.org/HDF5/doc/cpplus_RM/index.html)

The C++ API provides C++ wrappers for the HDF5 library.

**Corresponding C++ classes:**

| C++ Classes 					|
|------------------------------|
| Attribute						|
| DataSet						|
| Exception						|
| H5File						|
| Group							|
| IdComponent					|
| PropList and subclasses		|
| DataSpace						|
| DataType and subclasses		|

#### Interfaces

##### HighFive - Header-only C++ HDF5 Interface

[HighFive](https://github.com/BlueBrain/HighFive) is a modern header-only C++11 friendly interface for libhdf5.

* [HighFive Documentation](https://bluebrain.github.io/HighFive/)

HighFive supports STL vector/string, Boost::UBLAS, Boost::Multi-array, Eigen and Xtensor. It handles C++ from/to HDF5 with automatic type mapping. HighFive does not require additional libraries (see dependencies) and supports both HDF5 thread safety and Parallel HDF5 (contrary to the official hdf5 cpp).


