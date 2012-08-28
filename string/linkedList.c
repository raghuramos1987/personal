#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void insert(node *root, int data)
{
    node *n = malloc(sizeof(node));
    n->data = data;
    node *temp = root;
    while(temp->next!=NULL)
        temp = temp->next;
    n->next = NULL;
    temp->next = n;
    return;
}

void print(node *root)
{
    node *temp = root;
    while(temp->next!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

int main()
{
    int in[] = {1,2,3,4};
    int i;
    node *root = malloc(sizeof(node));
    root->next = NULL;
    root->data = 0;
    for(i=0;i<sizeof(in)/sizeof(int);i++)
        insert(root, in[i]);
    print(root);
    return 0;
}
