swig:
	swig -python -c++ -o odld_swig_wrap.cpp odld_swig.i
	gcc -I/home/boltzmann/apps/anaconda/include/python2.7 -c odld_swig.cpp -o odld_swig.o -fpic -std=c++0x
	gcc -I/home/boltzmann/apps/anaconda/include/python2.7 -c odld_swig_wrap.cpp -o odld_swig_wrap.o -fpic -std=c++0x -I/home/boltzmann/apps/anaconda/pkgs/numpy-1.13.3-py27hbcc08e0_0/lib/python2.7/site-packages/numpy/core/include
	g++ odld_swig.o odld_swig_wrap.o -o _odld_swig.so -shared -Wl,-soname,_odld_swig.so

clean:
	rm odld_swig.o *_wrap.* odld_swig.pyc _odld_swig.so
