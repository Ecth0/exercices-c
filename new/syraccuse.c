#include <stdio.h>
int main(int argc, char*argv[argc+1]) {
    const char *s=argv[1];
    int premier;
    int num = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - 48);
        }
        else {
            break;
        }
    }
    if fib
    
    printf("%d",num);
    return 0;
}