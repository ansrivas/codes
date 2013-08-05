# Make file for storage allocation program

output: file1.o file2.o file3.o
	gcc -o output file1.o file2.o file3.o

file1.o: file1.c prototype.h
	gcc -c file1.c

file2.o: file2.c prototype.h
	gcc -c file2.c

file3.o: file3.c prototype.h
	gcc -c file3.c

clean:
	rm *.o
	rm output

