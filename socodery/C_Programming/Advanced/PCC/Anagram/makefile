              ##################################################
              #  __________________________________________    #
              # /\                                         \   #
              # \_| Make file for PCC Anagram program      |   #
              #   |                                        |   #
              #   |   _____________________________________|_  #
              #    \_/_______________________________________/ #
              ##################################################



FLAGS = -DTRACE -g
#FLAGS = -g

anagram: main.o util.o anagram.h
	gcc -o anagram main.o util.o

main.o: main.c anagram.h
	gcc $(FLAGS) -c main.c
	
util.o: util.c anagram.h
	gcc $(FLAGS) -c util.c

clean:
	rm -f anagram
	rm -f *.o
