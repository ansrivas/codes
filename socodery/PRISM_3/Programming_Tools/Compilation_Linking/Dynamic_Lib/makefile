program: program.o libsimcomplex.so
	gcc -o program program.o -L. -lsimcomplex

libsimcomplex.so: simplelink.o complexlink.o
	gcc -shared -o libsimcomplex.so simplelink.o complexlink.o

simplelink.o:simplelink.c
	gcc -fpic -c simplelink.c

complexlink.o:complexlink.c
	gcc -fpic -c complexlink.c

program.o: program.c
	gcc -c program.c

clean:
	rm *.o
	rm *.so
	rm program

