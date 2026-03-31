#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

struct png {
    unsigned char magic[4];
    unsigned char nbytes;
    unsigned char version;
    unsigned char abi;
};


int main(void) {
    struct png mypngfile;

    int file = open("9mars",O_RDONLY);

    read(file, &mypngfile, sizeof(mypngfile));

    /*assert(mypngfile.magic[0]== '%o');*/
    assert(mypngfile.magic[1] == 'P');
    assert(mypngfile.magic[2] == 'N');
    assert(mypngfile.magic[3] == 'G');

    /*if (mypngfile.nbytes == 1)
        printf("Number of bytes: 32 bits.\n");
    else if (mypngfile.nbytes == 2)
        printf("Number of bytes: 64 bits.\n");
    else
        printf("Number of bytes: ???\n");*/
    close(file);
}

