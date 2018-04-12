#include <iostream> 
#include <cmath> 

void test()
{
  double a;
  a = 12;
  std::cout << exp(a) << std::endl;
  std::cout << cos(a) << std::endl;
  std::cout << sin(a) << std::endl;
}
/* testing numpy array inputting */
double sumArr(double* arr, int size)
{
  double sum = 0.;

  for(int i=0;i<size;i++)
  {
    sum += arr[i];
  }
  return sum;
}

double sumArr2(double* arr, int size1, int size2)
{
  double sum = 0.;

  for(int i=0;i<size1;i++)
  {
    for(int j=0;j<size2;j++)
    {
      int nIndexJ = i * size2 + j;
      std::cout << arr[nIndexJ] << std::endl;
      sum += arr[nIndexJ];
    }
  }
  return sum;
}

double sumArr3(double* arr, int size1, int size2, int size3)
{
  double sum = 0.;

  for(int i=0;i<size1;i++)
  {
    for(int j=0;j<size2;j++)
    {
      for(int k=0;k<size3;k++)
      {
        int nIndexJ = i * size2*size3 + j * size3 + k;
        std::cout << "ijk"  << std::endl;
        std::cout << i << std::endl;
        std::cout << j << std::endl;
        std::cout << k << std::endl;
        std::cout << "array value"  << std::endl;
        std::cout << arr[nIndexJ] << std::endl;
        std::cout << "array flat value"  << std::endl;
        std::cout << arr[i] << std::endl;
        sum += arr[nIndexJ];
      }
    }
  }
  return sum;
}

double modArr(double* arr, int size1, int size2, int size3)
{
  double sum = 0.;

  for(int i=0;i<size1;i++)
  {
    for(int j=0;j<size2;j++)
    {
      for(int k=0;k<size3;k++)
      {
        int nIndexJ = i + j * size1 + k * size2;
        if(i%10)
        {
          arr[nIndexJ] = 0;
        }
        std::cout << arr[nIndexJ] << std::endl;
        sum += arr[nIndexJ];
      }
    }
  }
  return sum;
}

double modArr2(double testvar, double* arr, int size1, int size2, int size3)
{
  double sum = 0.;

  for(int i=0;i<size1;i++)
  {
    for(int j=0;j<size2;j++)
    {
      for(int k=0;k<size3;k++)
      {
        int nIndexJ = i * size2 *size3 + j * size3 + k;
        std::cout << arr[nIndexJ] << std::endl;
        sum += arr[nIndexJ];
      }
    }
  }
  return sum;
}
