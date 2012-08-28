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
    struct list *child;
    list(int d);
};
void print(list *head)
{
    while (head != NULL)
    {
        cout<< head->data << " ";
        head = head->next;
    }
    cout<<endl;
}
list::list(int d):
    next(NULL),
    child(NULL),
    data(d)
{}

inline list* endof(list *h)
{
    while(h->next)
        h = h->next;
    return h;
}

list * flatten(list *head)
{
    list *lower, *elower;
    if (!head)
        return head;
    else if(head->child)
    {
        lower = flatten(head->child);
        elower = endof(lower);
        elower->next = head->next;
        head->next = lower;
        flatten(elower->next);
    }
    else
    {
        head->next = flatten(head->next);
    }
    return(head);
}

int main()
{
    list* head = new list(1);
    head->next = new list(2);
    head->next->next = new list(3);
    head->next->child = new list(4);
    list *six, *four;
    four = head->next->child;
    four->next = new list(6);
    six = four->next;
    four->child = new list(5);
    six->next = new list(8);
    six->child = new list(7);
    six->child->next = new list(9);
    head = flatten(head);
    print(head);
    return(0);
}
