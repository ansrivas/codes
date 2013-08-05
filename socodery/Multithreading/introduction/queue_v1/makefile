FLAGS= -Wall -g

all: libplatform.a

libplatform.a: queue.o msgqueue.o
	ar -q libplatform.a msgqueue.o queue.o

queue.o: queue.c prototype.h
	gcc -o queue.o $(FLAGS) -c queue.c

msgqueue.o: msgqueue.c msgqueue.h queue.h prototype.h
	gcc -o msgqueue.o $(FLAGS) -c msgqueue.c

clean:
	rm libplatform.a
	rm msgqueue.o
	rm queue.o
