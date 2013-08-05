              ##################################################
              #  __________________________________________    #
              # /\                                         \   #
              # \_| Make file for PCC Anagram port program |   #
              #   |                                        |   #
              #   |   _____________________________________|_  #
              #    \_/_______________________________________/ #
              ##################################################



FLAGS = -DTRACE_FEATURE -g
#FLAGS = -g

anagram: anagram_main.o anagram_util.o anagram_port.o
	gcc -o anagram anagram_main.o anagram_util.o anagram_port.o

anagram_main.o: anagram_main.c anagram.h anagram_error_msg.h
	gcc $(FLAGS) -c -Wall anagram_main.c
	
anagram_util.o: anagram_util.c anagram_util.h
	gcc $(FLAGS) -c -Wall anagram_util.c

angram_port.o: anagram_port.c anagram_port.h
	gcc $(FLAGS) -c -Wall anagram_port.c

clean:
	rm -f anagram
	rm -f *.o
