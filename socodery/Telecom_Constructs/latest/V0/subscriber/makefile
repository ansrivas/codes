all: subscriber

subscriber: subscriber.o
	gcc -g -o subscriber subscriber.o -L ../../platform -lplatform -lpthread

subscriber.o: subscriber.c
	gcc -o subscriber.o -g -c -Wall -I../../platform subscriber.c

clean:
	rm *.o
	rm subscriber
