#include <stdio.h>
int main()
{
    int somme=0;
    for (int i=3;i<1000;i++)
    {
        if (i%3==0 || i%5==0)
        {
            somme+=i;
        }
    }
    printf("%d",somme);
    return 0;
}