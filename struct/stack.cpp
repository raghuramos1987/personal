#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>
#include <iostream>

using namespace std;

struct list
{
    int data;
    struct list *next;
};

list* push(int nData, list *head)
{
    list *newHead = new(list);
    newHead->data = nData;
    newHead->next = head;
    return newHead;
}
int pop(list **head)
{
    if ((*head) == NULL)
    {
        cout<<"Empty stack pop!\n";
        return -1;
    }
    int temp = (*head)->data;
    list *del;
    del = *head;
    *head = del->next;
    return temp;
}

void print(list *head)
{
    while (head != NULL)
    {
        cout<< head->data << " ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    list *head = new(list);
    head->data = 10;
    head->next = NULL;
    print(head);
    head = push(15, head);
    print(head);
    cout<<pop(&head)<<endl;
    print(head);
    cout<<pop(&head)<<endl;
    cout<<pop(&head)<<endl;
    return 0;
}
