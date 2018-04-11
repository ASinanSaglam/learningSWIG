#include <iostream> 

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
        int nIndexJ = i * size2 + j * size3 + k;
        std::cout << arr[nIndexJ] << std::endl;
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
        int nIndexJ = i * size2 + j * size3 + k;
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
