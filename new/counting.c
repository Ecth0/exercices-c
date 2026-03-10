#include <stdio.h>
#include <string.h>

int main() {
    FILE* fptr;
    int lignes=0;
    int mots=0;
    char ligne[50];
    fptr = fopen("file.txt", "r");

    if (fptr == NULL) {
        printf("file.txt file failed to open.");
    }
    else {

        printf("The file is now opened.\n");
        while (fgets(ligne, 50, fptr)
               != NULL) {
            lignes+=1;
            printf("%s", ligne);
        }
        fclose(fptr);
        fptr = fopen("file.txt", "r");
        while (fgets(ligne, 50, fptr)
               != NULL) {
            /*printf("%ld\n",strlen(ligne));*/

            for (int i=0;i<strlen(ligne);i++)
            {
                if (ligne[i]==' ')
                {
                mots+=1;
                }
            }
        }
        printf("Lignes: %d Mots: %d\n",lignes,mots);

        fclose(fptr);
    }
    return 0;
}