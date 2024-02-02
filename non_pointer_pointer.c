#include <stdio.h>

int main() {
    int i;

    char char_array[5] = {'a', 'b' , 'c', 'd', 'e'};
    int int_array[5] = {1, 2, 3, 4, 5};

    long unsigned int hacky_pointer;

    hacky_pointer = (long unsigned int) char_array;

    for ( i = 0; i < 5; i++)
    {
        printf("[hacky pointer] points to %p, which contains the char '%c'\n", (void *) hacky_pointer, *((char *) hacky_pointer));
        hacky_pointer = hacky_pointer + sizeof(char);

    }

    hacky_pointer = ( long unsigned int) int_array;

    for ( i = 0; i < 5; i++)
    {
        printf("[hacky pointer] points to %p, which contains the integer %d\n", (void *) hacky_pointer, *((int *) hacky_pointer));
        hacky_pointer = hacky_pointer + sizeof(int);
    }
    
    
}