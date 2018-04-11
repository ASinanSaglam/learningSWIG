%module test
%{
  #define SWIG_FILE_WITH_INIT
  #include "test.h"
%}

%include "numpy.i"

%init %{
  import_array();
%}

%apply (double* IN_ARRAY1, int DIM1) {(double* arr, int size)}
%apply (double* INPLACE_ARRAY2, int DIM1, int DIM2) {(double* arr, int size1, int size2)}
%apply (double* INPLACE_ARRAY3, int DIM1, int DIM2, int DIM3) {(double* arr, int size1, int size2, int size3)}
%apply (double* INPLACE_ARRAY3, int DIM1, int DIM2, int DIM3) {(double* arr, int size1, int size2, int size3)}

%include "test.h"
