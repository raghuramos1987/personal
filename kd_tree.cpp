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

struct point
{
    int x,y;
};
void getInput(vector<point> *inp)
{
    int x,y,z;
    point p;
    do
    {
        cin>>p.x;cin>>p.y;
        inp->push_back(p);
    }while(p.x);
}

struct Node
{
    point data;
    struct Node *left, *right;
};

bool compx( const point& l, const point& r)
   { return l.x < r.x; }
bool compy( const point& l, const point& r)
   { return l.y < r.y; }

Node* construct_tree(vector<point> inp, int ind)
{
    Node *root = new Node;
    if(inp.size() == 0)
        return NULL;
    int half = inp.size()/2;
    if (half)
    if(ind ==0)
    {
        sort(inp.begin(), inp.end(), compx);
        vector<point> newinl(inp.begin(), inp.begin()+half);
        vector<point> newinr(inp.begin()+half+1, inp.end());
        root->left = construct_tree(newinl, 1);
        root->right = construct_tree(newinr, 1);
    }
    else
    {
        sort(inp.begin(), inp.end(), compy);
        vector<point> newinl(inp.begin(), inp.begin()+half);
        vector<point> newinr(inp.begin()+half+1, inp.end());
        root->left = construct_tree(newinl, 0);
        root->right = construct_tree(newinr, 0);
    }
    root->data = inp[half];
    return root;
}
void print(Node *root)
{
    if(!root)
        return;
    cout<<"Root:"<<root->data.x<<" "<<root->data.y<<endl;
    if(root->left)
    {
        cout<<"left:"<<root->left->data.x<<" "<<
            root->left->data.y<<"    ";
    }
    if(root->right)
    {
        cout<<"right:"<<root->right->data.x<<" "<<
            root->right->data.y<<"    ";
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}
int main()
{
    vector<point> inp;
    Node *root;
    getInput(&inp);
    root = construct_tree(inp, 0);
    print(root);
    return 0;
}
