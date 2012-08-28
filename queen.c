#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>


bool checkPos(int *qpos, int x, int y, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if ((y == qpos[i]) || (abs(x-i)==abs(y-qpos[i])))
            return false;
    }
    return true;
}
int main()
{
    int n;int *qpos, *klist;
    scanf("%d", &n);
    qpos = (int *)calloc(n,sizeof(int));
    klist = (int *)calloc(n,sizeof(int));
    int x,i,j,l;
    x = 0;
    int temp = n;
    for(i=0;i<n;i++)
        qpos[i]-=100;
    while(x!=n)
    {
        temp = x;
        for(i=klist[x];i<n;i++)
        {
            if(checkPos(qpos, x, i, n))
            {
                qpos[x++] = i;
                break;
            }
        }
        if(x == temp)
        {
            klist[x] = 0;
            klist[x-1] = qpos[x-1]+1;
            qpos[x-1] = -100;
            x--;
        }
    }
    for(i=0;i<n;i++)
        printf("%d\n",qpos[i]);
    return 0;
}
