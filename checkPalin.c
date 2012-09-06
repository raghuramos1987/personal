#include <stdio.h>
#include <string.h>

int getPalin(char *in)
{
    int count = 0;
    int i;
    for(i=0;i<strlen(in)-1;i++)
    {
        if(in[i] == in[i+1])
            count++;
        else if(i > 0)
        {
            if(in[i-1]==in[i+1])
                count++;
        }
    }
    return count;
}
int main(int argc, char **argv)
{
    if(argc>1)
        printf("%d\n", getPalin(argv[1]));
    return 0;
}
