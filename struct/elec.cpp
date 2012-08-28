#include <stdio.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>
#include <map>
#include <iostream>
#include <cstdlib>
#include <numeric>

using namespace std;

struct tree
{
    int time, data;
    vector<struct tree *> childV;
};
class PowerOutage
{
    public:
        int estimateTimeOut(vector <int> fromJunction,
                vector <int> toJunction, vector <int> ductLength);
        int findMax(map<int,tree> , int);
};
int PowerOutage::findMax(map<int,tree> main_t, int root)
{
    tree rNode = main_t[root];
    vector<int> maxV;
    int cmax, max = rNode.time;
    cmax = 0;
    if(!rNode.childV.empty())
    {
        for(vector<tree *>::iterator i=rNode.childV.begin();
                i!=rNode.childV.end();i++)
        {
            maxV.push_back(findMax(main_t, (*i)->data));
        }
        for(vector<int>::iterator i=maxV.begin();i!=maxV.end();i++)
        {
            cmax = (cmax<(*i))? (*i):cmax;
        }
    }
    return (max+cmax);
}
int PowerOutage::estimateTimeOut(vector <int> fromJunction,
        vector <int> toJunction, vector <int> ductLength)
{
    map<int, tree> main_tree;
    vector<int>::iterator i,j,k;
    i=fromJunction.begin();
    int root = (*i);
    j = toJunction.begin();
    k = ductLength.begin();
    pair<map<int, tree>::iterator, bool> ret;
    tree ins_t;
    for(i=fromJunction.begin();i != fromJunction.end(); i++,j++,k++)
    {
        ins_t.data = (*i);
        ins_t.time = 0;
        ret = main_tree.insert(pair<int,tree>(*i, ins_t));
        if(!ret.second)
        {
            if(main_tree.find(*j) == main_tree.end())
            {
                ins_t.data = (*j);
                ins_t.time = (*k);
                main_tree[*j] = ins_t;
            }
            ret.first->second.childV.push_back(&main_tree[*j]);
        }
        else
        {
            ins_t.data = (*j);
            ins_t.time = (*k);
            main_tree[*j] = ins_t;
            ret.first->second.childV.push_back(&main_tree[*j]);
        }
    }
    int dif = findMax(main_tree, root);
    return (accumulate(ductLength.begin(),
            ductLength.end(),-dif)*2+dif);
}
int main()
{
    int fromJ[]={0,0,0,1,4};
    int toJ[] = {1,3,4,2,5};
    int ductL[] = {10,10,5,10,100};
    vector<int> fromJunction (fromJ, fromJ+5);
    vector<int> toJunction (toJ, toJ+5);
    vector<int> ductLength(ductL, ductL+5);
    PowerOutage p;
    int dif = p.estimateTimeOut(fromJunction, toJunction, ductLength);
    return 0;
}
