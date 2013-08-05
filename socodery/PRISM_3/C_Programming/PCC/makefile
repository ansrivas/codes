# Make File for anagram program trace

FLAGS = -DTRACE_FEATURE -g -save-temps
#FLAGS = -g

anagram: anagram_main.o anagram_util.o anagram_error.o anagram.h
	gcc -o anagram anagram_main.o anagram_util.o anagram_error.o

anagram_main.o: anagram_main.c anagram.h
	gcc $(FLAGS) -c anagram_main.c
	
anagram_util.o: anagram_util.c anagram.h
	gcc $(FLAGS) -c anagram_util.c

anagram_error.o: anagram_error.c anagram.h
	gcc $(FLAGS) -c anagram_error.c
clean:
	rm -f anagram
	rm -f *.o
