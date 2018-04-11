%module test
%{
  #define SWIG_FILE_WITH_INIT
  #include "odld_swig.h"
%}

%include "numpy.i"

%init %{
  import_array();
%}

%apply (double 
(double* INPLACE_ARRAY3, int DIM1, int DIM2, int DIM3) {(double* arr, int size1, int size2, int size3)}
double calc_displacements(double twopi_by_A, double half_B, double sigma, double gradfactor, double reflect_at, double A, double B, double C, double x0, int coord_len, double* all_displacements, double* coords);

%include "odld_swig.h"
