FLAGS= -Wall -g
#FLAGS= -Wall -g -fpic

all: libqueue.a
#all: libqueue.so

libqueue.a: queue.o msgqueue.o
	ar -q libqueue.a msgqueue.o queue.o

#libqueue.so: queue.o msgqueue.o
#	gcc -shared -o libqueue.so msgqueue.o queue.o

queue.o: queue.c prototype.h
	gcc -o queue.o $(FLAGS) -c queue.c

msgqueue.o: msgqueue.c msgqueue.h queue.h prototype.h
	gcc -o msgqueue.o $(FLAGS) -c msgqueue.c

clean:
	rm msgqueue.o
	rm queue.o
	rm libqueue.a
#	rm libqueue.so
