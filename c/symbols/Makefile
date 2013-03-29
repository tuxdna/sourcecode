# export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.

g:
	cc -fPIC -shared -o libgreet.so greet.c

nog: 
	cc -fPIC -shared -o libnogreet.so nogreet.c


pre: stdio.h greet.h greet.c
	cpp -CC -I.  greet.c -o greet.preprocessed
