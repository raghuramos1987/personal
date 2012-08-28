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

class IntegerGenerator
{
    public:
        string nextInteger(vector <int> allowed, string current);
        bool checkIn(vector <int> allowed, string current);
        int checkG(vector<int> allowed, int num, int place);
};

bool IntegerGenerator::checkIn(vector <int> allowed, string current)
{
    int val;
    for(int i=0;i<current.length();i++)
    {
        stringstream ss;
        ss<<current[i];
        ss>>val;
        if((i==0)&&(val==0))
            return false;
        if(find(allowed.begin(),allowed.end(),val)==
                allowed.end()) return false;
    }
    return true;
}
int IntegerGenerator::checkG(vector<int> allowed, int num, int place)
{
    int ret=-1;
    int pl,rem,quo,net;
    pl = pow(10, place);
    rem = num%pl;
    quo = num/pl;
    for(vector<int>::iterator i=allowed.begin();i<allowed.end();i++)
    {
        if((*i)>rem)
        {
            quo *= pl;
            quo += (*i);
            return quo;
        }
    }
    if(ret == -1)
    {
        net = checkG(allowed, quo, place);
        net *= 10;
        net += allowed[0];
    }
    return net;
}

string IntegerGenerator::nextInteger(vector <int> allowed,
        string current)
{
    stringstream ss;
    int retI, place;
    string ret("");
    if(!checkIn(allowed, current))
    {
        ret += "INVALID INPUT";
        return ret;
    }
    sort(allowed.begin(),allowed.end());
    ss<<current;
    ss>>retI;
    for(int i=1;i<=current.length();i++)
    {
        retI = checkG(allowed, retI, i);
        if(retI == -1)
            continue;
        else
            break;
    }
    stringstream st;
    st<<retI;
    return st.str();
}

int main()
{
    IntegerGenerator s;
    int al[] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> all(al,al+10);
    cout<<all.size()<<endl;
    string cur("999");
    cout<<s.nextInteger(all, cur)<<endl;
    return 0;
}
