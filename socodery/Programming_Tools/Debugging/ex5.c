#include <stdio.h>
#include <stdlib.h>

void fillarray(int *array, int size) {
    int i;

    for(i = 0; i < size; i++) array[i] = i;
}

int main(int argc, char *argv[]) {
    int *numarray, i;

    numarray = malloc(atoi(argv[1]));
    fillarray(numarray, sizeof(numarray));
    for(i = 0; i < sizeof(numarray); i++) printf("%d\n", numarray[i]);

    return 0;
}



