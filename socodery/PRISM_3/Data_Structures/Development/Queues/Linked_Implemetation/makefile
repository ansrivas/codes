queue: queue_functions.o main.o
	gcc -o queue queue_functions.o main.o

queue_functions.o:queue_functions.c header.h
	gcc -c -I. -Wall queue_functions.c

main.o:main.c header.h
	gcc -c -I. -Wall main.c

clean :
	rm *.o
	rm queue
