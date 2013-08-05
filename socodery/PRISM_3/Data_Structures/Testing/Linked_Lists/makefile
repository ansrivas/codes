list: insert_functions.o delete_functions.o other_functions.o main.o
	gcc -o list insert_functions.o delete_functions.o other_functions.o main.o

insert_functions.o:insert_functions.c header.h
	gcc -c -I. -Wall insert_functions.c

delete_functions.o:delete_functions.c header.h
	gcc -c -I. -Wall delete_functions.c
 
other_functions.o:other_functions.c header.h
	gcc -c -I. -Wall other_functions.c

main.o:main.c header.h
	gcc -c -I. -Wall main.c

clean :
	rm *.o
	rm list
