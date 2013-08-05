FLAGS= -Wall -g
all: switch

switch: switch.o calllib.o callsm.o initsignals.o
	gcc -o switch -g switch.o callsm.o calllib.o initsignals.o -L ../../platform -lplatform -lpthread

initsignals.o: initsignals.c initsignals.h basictypes.h
	gcc -o initsignals.o $(FLAGS) -c -I../../platform initsignals.c

calllib.o: calllib.c calllib.h basictypes.h
	gcc -o calllib.o $(FLAGS) -c -I../../platform calllib.c

callsm.o: callsm.c callsm.h basictypes.h
	gcc -o callsm.o $(FLAGS) -c -I../../platform callsm.c

switch.o: switch.c callsm.h basictypes.h
	gcc -o switch.o $(FLAGS) -c -I../../platform switch.c

clean:
	rm *.o
	rm switch
