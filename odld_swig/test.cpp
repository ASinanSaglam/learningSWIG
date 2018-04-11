#include <iostream> 

/* testing numpy array inputting */
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

void calc_displacements()
{
}

        for istep in xrange(1,coord_len):
            x = coords[:,istep-1,0]
            
            xarg = twopi_by_A*(x - x0)
            
            eCx = numpy.exp(C*x)
            eCx_less_one = eCx - 1.0
           
            all_displacements[:,istep,0] = displacements = random_normal(scale=sigma, size=(n_segs,))
            grad = half_B / (eCx_less_one*eCx_less_one)*(twopi_by_A*eCx_less_one*sin(xarg)+C*eCx*cos(xarg))
            
            newx = x - gradfactor*grad + displacements
            if reflect_at is not None:
                # Anything that has moved beyond reflect_at must move back that much
                
                # boolean array of what to reflect
                to_reflect = newx > reflect_at
                
                # how far the things to reflect are beyond our boundary
                reflect_by = newx[to_reflect] - reflect_at
                
                # subtract twice how far they exceed the boundary by
                # puts them the same distance from the boundary, on the other side
                newx[to_reflect] -= 2*reflect_by
            coords[:,istep,0] = newx

        self.coord_len = pcoord_len
        self.coord_dtype = pcoord_dtype
        self.coord_ndim = 1
        
        self.initial_pcoord = numpy.array([8.0], dtype=self.coord_dtype)
        
        self.sigma = 0.001**(0.5)
        
        self.A = 2
        self.B = 10
        self.C = 0.5
        self.x0 = 1
        
        # Implement a reflecting boundary at this x value
        # (or None, for no reflection)
        self.reflect_at = 10.0
        #self.reflect_at = None


    def propagate(self, segments):
        
        A, B, C, x0 = self.A, self.B, self.C, self.x0
        
        n_segs = len(segments)
    
        coords = numpy.empty((n_segs, self.coord_len, self.coord_ndim), dtype=self.coord_dtype)
        
        for iseg, segment in enumerate(segments):
            coords[iseg,0] = segment.pcoord[0]
            
        twopi_by_A = 2*PI/A
        half_B = B/2
        sigma = self.sigma
        gradfactor = self.sigma*self.sigma/2
        coord_len = self.coord_len
        reflect_at = self.reflect_at
        all_displacements = numpy.zeros((n_segs, self.coord_len, self.coord_ndim), dtype=self.coord_dtype)
        odld_swig.calc_displacements(twopi_by_A, half_B, sigma, gradfactor, coord_len, reflect_at, A, B, C, x0, all_displacements, coords)
            
        for iseg, segment in enumerate(segments):
            segment.pcoord[...] = coords[iseg,:]
            segment.data['displacement'] = all_displacements[iseg]
            segment.status = segment.SEG_STATUS_COMPLETE
    
        return segments
