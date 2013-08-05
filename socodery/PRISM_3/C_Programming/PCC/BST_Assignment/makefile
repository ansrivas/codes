              ##################################################
              #  __________________________________________    #
              # /\                                         \   #
              # \_| Make file for Binary Search Tree       |   #
              #   |                                        |   #
              #   |   _____________________________________|_  #
              #    \_/_______________________________________/ #
              ##################################################


binary_tree: bst_main.o bst_func_defin.o bst_node.h bst_func_proto.h
	gcc -g -o binary_tree bst_main.o bst_func_defin.o

bst_main.o: bst_main.c bst_node.h bst_func_proto.h
	gcc -c -g bst_main.c

bst_func_defin.o: bst_func_defin.c bst_node.h bst_func_proto.h
	gcc -c -g bst_func_defin.c

clean:
	rm binary_tree
	rm *.o

