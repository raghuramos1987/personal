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

int getSum(vector<int> in, int ind)
{
    vector<int> sum(in.size()-1,0);
    int i,j;
    for(i=ind;i<sum.size();i++)
    {
        sum[i] = in[ind]+in[i+1];
    }
    for(i=0;i<sum.size();i++)
        cout<<sum[i]<<" ";
    cout<<endl;
    for(j=ind;j<sum.size();j++)
    for(i=j+1;i<in.size();i++)
    {
        cout<<sum[j]+in[i]<<" ";
        if(!(sum[j]+in[i]))
            cout<<"Found one "<<i<<endl;
    }
    cout<<endl;
    return 0;
}

int main()
{
    int in[] = {5,0,-1,1,-5,1};
    vector<int> inp (in, in+6);
    for(int i=0;i<inp.size();i++)
        cout<<inp[i]<<" ";
    cout<<endl;
    for(int i=0;i<inp.size()-1;i++)
        getSum(inp, i);
}
