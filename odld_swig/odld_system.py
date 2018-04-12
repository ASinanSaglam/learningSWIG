from __future__ import print_function, division
import numpy, odld_swig
from west.propagators import WESTPropagator
from west.systems import WESTSystem
from westpa.binning import RectilinearBinMapper

PI = numpy.pi
from numpy import sin, cos, exp
from numpy.random import normal as random_normal

pcoord_len = 21
pcoord_dtype = numpy.double

class ODLDPropagator(WESTPropagator):
    def __init__(self, rc=None):
        super(ODLDPropagator,self).__init__(rc)
        
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

    def get_pcoord(self, state):
        '''Get the progress coordinate of the given basis or initial state.'''
        state.pcoord = self.initial_pcoord.copy()
                
    def gen_istate(self, basis_state, initial_state):
        initial_state.pcoord = self.initial_pcoord.copy()
        initial_state.istate_status = initial_state.ISTATE_STATUS_PREPARED
        return initial_state

    def propagate(self, segments):
        
        A, B, C, x0 = self.A, self.B, self.C, self.x0
        
        n_segs = len(segments)
    
        coords = numpy.empty((n_segs, self.coord_len, self.coord_ndim), dtype=self.coord_dtype)
        
        for iseg, segment in enumerate(segments):
            coords[iseg,0] = segment.pcoord[0]
            
        sigma = numpy.double(self.sigma)
        reflect_at = numpy.double(self.reflect_at)
        A = numpy.double(A)
        B = numpy.double(B)
        C = numpy.double(C)
        x0 = numpy.double(x0)
        #all_displacements = numpy.zeros((n_segs, self.coord_len, self.coord_ndim), dtype=self.coord_dtype)
        odld_swig.calc_displacements(sigma, reflect_at, A, B, C, x0, coords)
            
        for iseg, segment in enumerate(segments):
            segment.pcoord[...] = coords[iseg,:]
            #segment.data['displacement'] = all_displacements[iseg]
            segment.status = segment.SEG_STATUS_COMPLETE
    
        return segments

class ODLDSystem(WESTSystem):
    def initialize(self):
        self.pcoord_ndim = 1
        self.pcoord_dtype = pcoord_dtype
        self.pcoord_len = pcoord_len
        
        #self.bin_mapper = RectilinearBinMapper([[0,1.3] + list(numpy.arange(1.4, 10.1, 0.1)) + [float('inf')]])
	self.bin_mapper = RectilinearBinMapper([ list(numpy.arange(0.0, 10.1, 0.1)) ])
        self.bin_target_counts = numpy.empty((self.bin_mapper.nbins,), numpy.int_)
        self.bin_target_counts[...] = 10
        
