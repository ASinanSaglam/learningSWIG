swig:
	swig -python -c++ -o test_wrap.cpp test.i
	gcc -I/home/boltzmann/apps/anaconda/include/python2.7 -c test.cpp -o test.o -fpic -std=c++0x
	gcc -I/home/boltzmann/apps/anaconda/include/python2.7 -c test_wrap.cpp -o test_wrap.o -fpic -std=c++0x -I/home/boltzmann/apps/anaconda/pkgs/numpy-1.13.3-py27hbcc08e0_0/lib/python2.7/site-packages/numpy/core/include
	g++ test.o test_wrap.o -o _test.so -shared -Wl,-soname,_test.so

clean:
	rm test.o *_wrap.* test.pyc _test.so
