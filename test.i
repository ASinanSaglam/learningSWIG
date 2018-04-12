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

/* Custom typemap for our func */
%typecheck(SWIG_TYPECHECK_DOUBLE_ARRAY,
           fragment="NumPy_Macros")
  (DATA_TYPE* INPLACE_ARRAY3, DIM_TYPE DIM1, DIM_TYPE DIM2, DIM_TYPE DIM3, PTYPE PAR)
{
  $1 = is_array($input) && PyArray_EquivTypenums(array_type($input),
                                                 DATA_TYPECODE);
}
%typemap(in,
         fragment="NumPy_Fragments")
  (DATA_TYPE* INPLACE_ARRAY3, DIM_TYPE DIM1, DIM_TYPE DIM2, DIM_TYPE DIM3, PTYPE PAR)
  (PyArrayObject* array=NULL)
{
  array = obj_to_array_no_conversion($input, DATA_TYPECODE);
  if (!array || !require_dimensions(array,3) || !require_contiguous(array) ||
      !require_native(array)) SWIG_fail;
  $1 = (DATA_TYPE*) array_data(array);
  $2 = (DIM_TYPE) array_size(array,0);
  $3 = (DIM_TYPE) array_size(array,1);
  $4 = (DIM_TYPE) array_size(array,2);
}

%apply (double NPY_DOUBLE, double* INPLACE_ARRAY3, int DIM1, int DIM2, int DIM3) {(double testvar, double* arr, int size1, int size2, int size3)}

%include "test.h"
