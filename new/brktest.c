#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int * mon_int;
    brk(mon_int);
    int stack = 42;
    *mon_int=5;

    printf("%p\n%d\n",mon_int,*mon_int);
    printf("%p\n",&stack);
    return 0;

}