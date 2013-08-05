              ##################################################
              #  __________________________________________    #
              # /\                                         \   #
              # \_| Make file for day program		   |   #
              #   |                                        |   #
              #   |   _____________________________________|_  #
              #    \_/_______________________________________/ #
              ##################################################


day: day_main.o day_functions.o
	gcc -o day day_main.o day_functions.o

day_main.o: day_main.c day_header.h
	gcc -c -Wall day_main.c 

day_functions.o: day_functions.c day_header.h
	gcc -c -Wall day_functions.c 
clean:
	rm day
	rm *.o


