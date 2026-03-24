#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int * mon_int = malloc(sizeof(*mon_int));
    *mon_int=5;
    int stack = 42;

    printf("%p\n",mon_int);
    printf("%p\n",&stack);
    

    free(mon_int);
    return 0;

}