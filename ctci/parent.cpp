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

vector<string> paren(int n)
{
    vector<string> ret,tret;
    stringstream ss;
    if(n == 1)
        ret.push_back("()");
    else
    {
        tret = paren(n-1);
        for(vector<string>::iterator i=tret.begin();i!=tret.end();i++)
        {
            ss.str("");
            ss<<"("<<(*i)<<")";
            ret.push_back(ss.str());
            ss.str("");
            ss<<"()"<<(*i);
            ret.push_back(ss.str());
            ss.str("");
            ss<<(*i)<<"()";
            ret.push_back(ss.str());
        }
    }
    //for(vector<string>::iterator i=ret.begin();i!=ret.end();i++)
        //cout<<*i<<" ";
    //cout<<endl;
    return ret;
}


int main()
{
    vector<string> m;
    m = paren(3);
    for(vector<string>::iterator i=m.begin();i!=m.end();i++)
        cout<<*i<<" ";
    cout<<endl;
    return 0;
}


