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

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int d)
    {
        data = d;
        left=right=NULL;
    }
};

void constructTree(Node *root)
{
}

void inorderSuc(Node *root, int data, int visited)
{
    if(root == NULL)
        return;
    static int nVisited = visited;
    inorderSuc(root->left, data, nVisited);
    if(nVisited == 1)
    {
        cout<<"inorder: "<<root->data<<endl;
        nVisited = 0;
        return;
    }
    if(root->data == data)
        nVisited = 1;
    inorderSuc(root->right, data, nVisited);
}

void preorderSuc(Node *root, int data, int visited)
{
    if(root == NULL)
        return;
    static int nVisited = visited;
    if(nVisited == 1)
    {
        cout<<"preorder: "<<root->data<<endl;
        nVisited = 0;
        return;
    }
    if(root->data == data)
        nVisited = 1;
    preorderSuc(root->left, data, nVisited);
    preorderSuc(root->right, data, nVisited);
}

void postorderSuc(Node *root, int data, int visited)
{
    if(root == NULL)
        return;
    static int nVisited = visited;
    postorderSuc(root->left, data, nVisited);
    postorderSuc(root->right, data, nVisited);
    if(nVisited == 1)
    {
        cout<<"preorder: "<<root->data<<endl;
        nVisited = 0;
        return;
    }
    if(root->data == data)
        nVisited = 1;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->right->left = new Node(3);
    root->right->right = new Node(1);
    inorderSuc(root, 7, 0);
    preorderSuc(root, 7, 0);
    postorderSuc(root, 7, 0);
    return 0;
}
