%module odld_swig
%{
  #define SWIG_FILE_WITH_INIT
  #include "odld_swig.h"
%}

%include "numpy.i"

%init %{
  import_array();
%}

%apply (int DIM1, int DIM2, int DIM3, double* INPLACE_ARRAY3) {(int dim1, int dim2, int dim3, double* coords)}
%include "odld_swig.h"
