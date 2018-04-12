#define _USE_MATH_DEFINES

#include <iostream> 
#include <random> 
#include <cmath> 

void calc_displacements(double sigma, double reflect_at, double A, double B, double C, double x0, int dim1, int dim2, int dim3, double* coords)
{
  /* x is the array of starting coordinates
   * coords is 3 dim array, walkerID/step size/dimensionality of the coordinate
   * x is the last step of the 1st dim of every walker, e.g. coords[:,istep-1,0] 
   * also note that both all_disp and coords are the same size 3 dim arrays */
  double x, xarg, newx;
  double displacement;
  double eCx, eCx_less_one;
  double grad;
  double reflect_by;
  int flat_index, prev_index;

  double twopi_by_A = 2 * M_PI/A;
  double half_B = B/2;
  double gradfactor = sigma*sigma/2;

  /* Let's get the normal distribution with the correct sigma */
  std::default_random_engine gen;
  std::normal_distribution<double> normal_dist(0.0,sigma);
  
  //std::cout << "dimensionality" << std::endl;
  //std::cout << dim1 << std::endl;
  //std::cout << dim2 << std::endl;
  //std::cout << dim3 << std::endl;
  /* Start the new coordinate calculation */
  //std::cout << "Starting the loop" << std::endl;
  for(int i=0;i<dim1;i++)
  {
    //std::cout << "In top for loop" << std::endl;
    //std::cout << i << std::endl;
    for(int j=0;j<dim2;j++)
    {
      //std::cout << "In 2nd for loop" << std::endl;
      //std::cout << j << std::endl;
      for(int k=0;k<dim3;k++)
      {
        //std::cout << "In 3rd for loop" << std::endl;
        //std::cout << k << std::endl;
        if(k==0 && (j>0))
        {
          //std::cout << "In primary if" << std::endl;
          flat_index = i * dim2 * dim3 + j * dim3 + k;
          prev_index = i * dim2 * dim3 + (j-1) * dim3 + k;
          x = coords[prev_index];
          xarg = twopi_by_A * (x - x0);
          eCx = exp(C*x);
          eCx_less_one = eCx - 1;
          /* We are getting a random number from a normal dist for a random kick in odld */
          displacement = normal_dist(gen);
          /* Calculate gradient */
          grad = half_B / (eCx_less_one * eCx_less_one) * (twopi_by_A * eCx_less_one * sin(xarg) + C*eCx * cos(xarg));
          /* Calculate next positions */
          newx = x - gradfactor * grad + displacement;
          /* Check for reflecting boundary 
           * Note that in this implementation I'm assuming that a negative value means to just not
           * reflect anything, for simplicity so I don't have to deal w/ NaN/None types */
          if(reflect_at>0)
          {
            if(newx > reflect_at)
            {
              /* Puts the particles back into the otherside of the reflecting boundary */
              reflect_by = newx - reflect_at;
              newx -= 2*reflect_by;
            }
          }
          /* Update coordinates */
          //std::cout << "Updating coordinates" << std::endl;
          coords[flat_index] = newx;
        }
      }
    }
  }
  //std::cout << "Ended the loop" << std::endl;
}
