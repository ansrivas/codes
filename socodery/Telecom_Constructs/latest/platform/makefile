FLAGS= -Wall -g

all: libplatform.a

libplatform.a: platform.o idgenerator.o list.o timerutility.o threadmgr.o msgmgr.o connmgr.o msgqueue.o queue.o
	ar -q libplatform.a platform.o idgenerator.o list.o timerutility.o threadmgr.o msgmgr.o connmgr.o msgqueue.o queue.o

connmgr.o: connmgr.c prototype.h
	gcc -o connmgr.o $(FLAGS) -c connmgr.c

msgmgr.o: msgmgr.c msgmgr.h connmgr.h prototype.h
	gcc -o msgmgr.o $(FLAGS) -c msgmgr.c

queue.o: queue.c prototype.h
	gcc -o queue.o $(FLAGS) -c queue.c

msgqueue.o: msgqueue.c msgqueue.h queue.h prototype.h
	gcc -o msgqueue.o $(FLAGS) -c msgqueue.c

threadmgr.o: threadmgr.c threadmgr.h prototype.h
	gcc -o threadmgr.o $(FLAGS) -c threadmgr.c

idgenerator.o: idgenerator.c idgenerator.h prototype.h
	gcc -o idgenerator.o $(FLAGS) -c idgenerator.c

list.o: list.c list.h idgenerator.h prototype.h
	gcc -o list.o $(FLAGS) -c list.c

timerutility.o: timerutility.c timerutility.h list.h idgenerator.h prototype.h
	gcc -o timerutility.o $(FLAGS) -c timerutility.c

platform.o: platform.c timerutility.h prototype.h
	gcc -o platform.o $(FLAGS) -c platform.c
clean:
	rm libplatform.a
	rm platform.o
	rm timerutility.o
	rm idgenerator.o
	rm list.o
	rm threadmgr.o
	rm msgmgr.o
	rm connmgr.o
	rm msgqueue.o
	rm queue.o
