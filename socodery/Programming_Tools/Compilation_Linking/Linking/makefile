program: program.o simplelink.o 
	gcc -o program program.o simplelink.o

simplelink.o:simplelink.c
	gcc -c simplelink.c

program.o: program.c
	gcc -c program.c

clean:
	rm *.o
	rm program

