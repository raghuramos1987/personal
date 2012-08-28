#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>

void print(int in[], int len)
{
    int i;
    for(i=0;i<len;i++)
        printf("%d,", in[i]);
    printf("\n");
    return;
}

void derange(int in[], int len, int fix)
{
    int temp;
    if(len==2)
    {
        temp = in[0];
        in[0] = in[1];
        in[1] = temp;
        return;
    }

}

int main()
{
    int in[] = {0,1,2};
    int i, j, len = 3;
    int *out; out = malloc(sizeof(int)*len);
    for(i=0;i<len;i++)
        out[i] = -1;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            if((j!=i) && (out[j]==-1))
            {
                out[j] = in[i];
                break;
            }
        }
    }
    print(out,len);
    return 0;
}
