#include <string.h>
#include <stdio.h>

int main(void) {
    // I prefilled this variable for you, you don't need to touch it.
    const char *whetting_your_appetite = (
        "Ada Lovelace's notes were labelled alphabetically from A to G. "
        "In Note G, she describes an algorithm for the Analytical Engine "
        "to compute Bernoulli numbers. "
        "It is considered to be the first published algorithm ever "
        "specifically tailored for implementation on a computer, and "
        "Ada Lovelace has often been cited as the first computer programmer "
        "for this reason."
    );
    int compt=0;
    //printf("%s\n",whetting_your_appetite);
    do
    {
        compt+=1;
    }while (whetting_your_appetite[compt] != '\0');
    printf("%d",compt);
    return 0;

}