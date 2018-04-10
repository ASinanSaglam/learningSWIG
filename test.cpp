#include <iostream> 

double testVar = 5.0;

/* Factorial */
int fact(int n)
{
  if (n <= 1) return 1;
  else return n*fact(n-1);
}

/* Let's test a variable */
/*
int main() 
{
  std::cout << fact(testVar);
  std::cout << "\n";
  return 0;
}
*/
