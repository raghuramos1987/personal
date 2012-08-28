#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

void perm(char *in, char *out, int len, int lev, int st)
{
    int i;
    int olen;
    i = st+lev;
    olen = strlen(out);
    out[olen] = in[i];
    olen++;
    out[olen] = '\0';
    printf("%s\n",out);
    if (i<(len-1))
    perm(in, out, len, lev, st+1);
    out[olen-1] = out[olen];
}
int main(int argc, char **argv)
{
    char *in, *out;
    int len, i;
    in = (char *)malloc(sizeof(char)*10);
    out = (char *)malloc(sizeof(char)*100);
    fgets(in,10,stdin);
    in[strlen(in)-1] = '\0';
    out[0] = '\0';
    len = strlen(in);
    for(i=0;i<len;i++)
    {
        perm(in, out, len, i, 0);
        out[0] = '\0';
    }
    return 0;
}
