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
    bool visited;
    struct Node *left, *right, *parent;
    Node(int d)
    {
        data = d;
        visited = false;
        left=right=parent=NULL;
    }
};

void inorderSuc(Node *root)
{
    while(true)
    {
        if(root == NULL)
            return;
        while(root->left != NULL)
        {
            if (root->left->visited)
                break;
            root = root->left;
        }

        if(root->visited)
            return;
        root->visited = true;
        cout<<root->data<<" ";
        fflush(stdout);

        if(root->right != NULL)
        {
            root = root->right;
            continue;
        }
        if(root == NULL)
            return;
        while(root->visited)
        {
            if (root->parent == NULL)
                break;
            root = root->parent;
        }
    }
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->right = new Node(4);
    root->left->right->parent = root->left;
    root->left->left = new Node(2);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    root->right->right->parent = root->right;
    root->right->left->parent = root->right;
    root->left->left->parent  = root->left;
    root->right->parent = root;
    root->left->parent = root;
    inorderSuc(root);
    cout<<endl;
    //preorderSuc(root, 7, 0);
    //postorderSuc(root, 7, 0);
    return 0;
}
