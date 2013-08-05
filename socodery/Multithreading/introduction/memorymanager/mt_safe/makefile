libmem.a: mem_lib.o
	ar -r libmem.a mem_lib.o

mem_lib.o: mem_lib_v1.c
	gcc -o mem_lib.o -g -c mem_lib_v1.c

clean:
	rm *.o
	rm libmem.a
