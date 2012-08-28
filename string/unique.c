#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#define CHARSET 255


void unique(char *s)
{
    unsigned int flag;
    int i,tail;
    tail = 0;
    flag = 0;
    for(i=0;i<strlen(s);i++)
    {
        if(flag&(1<<s[i]))
            continue;
        else
        {
            flag |= (1<<s[i]);
            s[tail] = s[i];
            tail++;
        }
    }
    s[tail] = '\0';
    return;
}

void swap(char *s,int i,int j)
{
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    return;
}
bool myStrcmp(char *s, char *f, int i)
{
    int j;
    int lenf = strlen(f);
    for(j=0;j<lenf;j++)
    {
        if(s[i] != f[j])
            return false;
    }
    return true;
}

char* replace(char *s, char *f, char *r)
{
    int i, j, k, len, count, lenf, lenr, newLen;
    char *n;
    count = 0;
    len = strlen(s);
    lenf = strlen(f);
    lenr = strlen(r);
    for(i=0;i<len;i++)
    {
        if(myStrcmp(s,f,i))
            count++;
    }
    if(lenr>lenf)
    {
        newLen = (len+count*(lenr-lenf));
        n = malloc(newLen*sizeof(char));
    }
    else
    {
        printf("Cant do this yet! ");
        return;
    }
    k = 0;
    for(i=0;i<newLen;i++)
    {
        if(myStrcmp(s,f,k))
        {
            for(j=0;j<lenr;j++)
            {
                n[i] = r[j];
                i++;
            }
            i--;
        }
        else
            n[i] = s[k];
        k++;
    }
    return n;
}

void reverse(char *s)
{
    int i;
    int k = strlen(s);
    k--;
    for(i=0;i<strlen(s)/2;i++)
        swap(s, i, k--);
    return;
}
int main(int argc, char **argv)
{
    char *s, *f, *r;
    int i;
    s = (char *)malloc(100);
    f = (char *)malloc(100);
    r = (char *)malloc(100);
    fgets(s, 100, stdin);
    fgets(f, 100, stdin);
    fgets(r, 100, stdin);
    /*if(!)*/
    /*{*/
        /*printf("Error");*/
        /*return -1;*/
    /*}*/
    /*argv[2] = " ";*/
    /*argv[3] = "%20";*/
    int len = sizeof(char)*strlen(s);
    int lenf = sizeof(char)*strlen(f);
    int lenr = sizeof(char)*strlen(r);
    s = realloc(s,len);
    f = realloc(f,lenf);
    r = realloc(r,lenr);
    /*strcpy(s, argv[1]);*/
    /*strcpy(f, argv[2]);*/
    /*strcpy(r, argv[3]);*/
    s[len-1] = '\0';
    f[lenf-1] = '\0';
    r[lenr-1] = '\0';
    printf("In:%s\n",s);
    printf("find:%s\n",f);
    printf("replace:%s\n",r);
    /*unique(s);*/
    /*printf("Unique=%s\n",s);*/
    /*reverse(s);*/
    char *n = replace(s, f, r);
    printf("%s\n",n);
    /*free(s);*/
    return 0;
}
