#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

void move(int from, int to, int m)
{
    printf("move %d from %d to %d\n", m, from, to);
    return;
}
void tower(int from, int mid, int to, int in)
{
    if(in!=1)
    {
        tower(from, to, mid, in-1);
        move(from,to,in);
        tower(mid,from,to,in-1);
    }
    else
        move(from, to, in);
    return;
}
int main(int argc, char **argv)
{
    int in;
    scanf("%d", &in);
    tower(1,2,3,in);
    return;
}
