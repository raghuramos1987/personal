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

vector<string> subset(vector<string> set)
{
    vector<string> ret,tret;
    string a = "";
    if (set.size() == 1)
    {
        ret.push_back(a);
        ret.push_back(set[0]);
    }
    else
    {
        vector<string> n(set.begin()+1, set.end());
        tret = subset(n);
        for(vector<string>::iterator i=tret.begin();i!=tret.end();i++)
        {
            string temp(*i);
            ret.push_back(temp.append(set[0]));
        }
        ret.insert(ret.end(),tret.begin(),tret.end());
    }
    return ret;
}

int main()
{
    vector<string> ar;
    ar.push_back("a");
    ar.push_back("b");
    ar.push_back("c");
    ar.push_back("d");
    vector<string> ret;
    ret = subset(ar);
    for(vector<string>::iterator i=ret.begin();i!=ret.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    return 0;
}
