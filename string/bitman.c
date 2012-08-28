#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int n, m, i, j, flag;
    scanf("%d %d %d %d",&n,&m,&i,&j);
    flag = floor(pow(2,j-i))-1;
    flag = flag << i;
    m = m&(~flag);
    m = m|(flag&n);
    printf("%d %d\n",n,m);
    return 0;
}
