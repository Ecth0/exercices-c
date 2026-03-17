int my_atoi(int argc, char*argv[argc+1] ) {
    const char *s=argv[1];
    int num = 0;
    int negatif=0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - 48);
        }
        else if (s[i] == 45)
        {
            negatif=1;
        }
        else {
            break;
        }
    }
    if (negatif==1)
    {
        return -num;
    }
    else
    {
        return num;
    }
}

