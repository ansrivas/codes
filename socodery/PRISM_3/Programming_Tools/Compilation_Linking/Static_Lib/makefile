program: program.o libsimcomplex.a
	gcc -o program program.o -L. -lsimcomplex

program.o: program.c
	gcc -c program.c

libsimcomplex.a: simplelink.o complexlink.o
	ar -r libsimcomplex.a simplelink.o complexlink.o

simplelink.o:simplelink.c
	gcc -c simplelink.c

complexlink.o:complexlink.c
	gcc -c complexlink.c

clean:
	rm *.o
	rm *.a
	rm program

