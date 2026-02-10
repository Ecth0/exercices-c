#include <stdio.h> 

int main()
{
    unsigned long somme=0;
    unsigned long carre=0;
    for (unsigned long i=1; i<=451000; i++)
    {
        carre=i*i;
        if (carre%2!=0)
        {
            somme+=carre;
        }
        printf("%lu\n",somme);
    }
    return 0;
}