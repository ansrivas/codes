stack: stack_functions.o main.o
	gcc -o stack stack_functions.o main.o

stack_functions.o:stack_functions.c header.h
	gcc -c -I. -Wall stack_functions.c

main.o:main.c header.h
	gcc -c -I. -Wall main.c

clean :
	rm *.o
	rm stack
