/*******************************************************************
* File Name :
* Purpose :
* Created By :  Raghuram Onti Srinivasan
* Email         onti@cse.ohio-state.edu
*******************************************************************/
#include <stdio.h>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

class mStack
{
    vector< stack<int> > mStack;
    int size;
    public:
        void push(int d);
        int pop();
        void setSize(int s);
};
inline void mStack::setSize(int s)
{
    size = s;
}


void mStack::push(int d)
{
    if(mStack.empty())
    {
        stack<int> next;
        mStack.push_back(next);
    }
    vector< stack<int> >::iterator i = mStack.end()-1;
    if(i->size() >= size)
    {
        cout<<"Next stack\n";
        stack<int> next;
        next.push(d);
        mStack.push_back(next);
    }
    else
    {
        i->push(d);
    }
}

int mStack::pop()
{
    vector< stack<int> >::iterator i = mStack.end()-1;
    if(i->empty())
    {
        cout<<"Empty stack pop!\n";
        return -1;
    }
    int ret = i->top();
    i->pop();
    if (i->size() == 0)
        mStack.pop_back();
    return ret;
}

int main()
{
    int choice, val;
    mStack S;
    S.setSize(3);
    while(choice != -1)
    {
        cout<<"Enter Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 0:
                cout<<"Enter Value: ";
                cin>>val;
                S.push(val);
                break;
            case 1:
                cout<<S.pop()<<endl;
                break;
            default:
                break;
        }
    }
}
