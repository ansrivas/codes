
queue: queue_main.o queue_functions.o
	gcc -o queue -g queue_main.o queue_functions.o

queue_main.o: queue_main.c queue_prototypes.h
	gcc -c -g queue_main.c

queue_functions.o: queue_functions.c
	gcc -c -g queue_functions.c

clean:
	rm queue
	rm *.o

