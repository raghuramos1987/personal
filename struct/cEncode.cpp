#include <stdio.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>
#include <iostream>
#include <cstdlib>

using namespace std;


class BinaryCode
{
    public:
        vector<string> decode(string mesg);
};

vector<string> BinaryCode::decode(string mesg)
{
    vector<string> ret;
    stringstream ss,ssd;
    int temp;
    int tr = 2;
    string s(""), sd("");
    vector<int> retI1, retI2;
    reverse(mesg.begin(),mesg.end());
    int temp2;
    while(tr--)
    {
        for(int i=0;i<mesg.length();i++)
        if(tr == 1)
        {
            if(i==0)
            {
                if (!((mesg.compare(0,1,"0") == 0)||
                            (mesg.compare(0,1,"1") == 0)))
                {
                    ret.push_back("NONE");
                    break;
                }
                retI1.push_back(0);
            }
            else
            {
                temp = mesg[i-1]-'0';
                if((i+1) == mesg.length())
                {
                    temp = mesg[i]-'0';
                    temp2 = temp-retI1[i-1];
                    if((temp2 == 0) ||(temp2==1))
                        retI1.push_back(temp2);
                    else
                    {
                        ret.push_back("NONE");
                        break;
                    }
                    for(vector<int>::reverse_iterator i=retI1.rbegin();
                            i!=retI1.rend();i++)
                    {
                        ss<<(*i);
                    }
                    ss>>s;
                    ret.push_back(s);
                    break;
                }
                else if(i>=2)
                    temp2 = temp-retI1[i-2]-retI1[i-1];
                else
                    temp2 = temp-retI1[i-1];
                if((temp2 == 0) ||(temp2==1))
                    retI1.push_back(temp2);
                else
                {
                    ret.push_back("NONE");
                    break;
                }
            }
        }
        else
        {
            if(i==0)
            {
                if(!((mesg.compare(0,1,"2") == 0)||
                          (mesg.compare(0,1,"1") == 0)))
                {
                    ret.push_back("NONE");
                    break;
                }
                retI2.push_back(1);
            }
            else
            {
                temp = mesg[i-1]-'0';
                if((i+1) == mesg.length())
                {
                    temp = mesg[i]-'0';
                    temp2 = temp-retI2[i-1];
                    if((temp2 == 0) ||(temp2==1))
                        retI2.push_back(temp2);
                    else
                    {
                        ret.push_back("NONE");
                        break;
                    }
                    for(vector<int>::reverse_iterator i=retI2.rbegin();
                            i!=retI2.rend();i++)
                    {
                        ssd<<(*i);
                    }
                    ssd>>sd;
                    ret.push_back(sd);
                    break;
                }
                else if(i>=2)
                    temp2 = temp-retI2[i-2]-retI2[i-1];
                else
                    temp2 = temp-retI2[i-1];
                if((temp2 == 0) ||(temp2==1))
                    retI2.push_back(temp2);
                else
                {
                    ret.push_back("NONE");
                    break;
                }
            }
        }
    }
    return ret;
}
int main()
{
    BinaryCode b;
    vector<string> ret;
    string mesg("12221112222221112221111111112221111");
    ret = b.decode(mesg);
    for(vector<string>::iterator i=ret.begin();i!=ret.end();i++)
        cout<<(*i)<<" ";
    cout<<endl;
    return 0;
}
