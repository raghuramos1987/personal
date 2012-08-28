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

class SubstitutionCode
{
    public:
        int getValue(string key, string code);
};

int SubstitutionCode::getValue(string key, string code)
{
    map<char, int> kmap;
    string ret("");
    stringstream ss;
    int re,i=0;
    for(i=0;i<key.length()-1;i++)
    {
        kmap[key[i]] = i+1;
    }
    kmap[key[i]] = 0;
    for(int i=0;i<code.length();i++)
    {
        if(kmap.find(code[i])==kmap.end())
            continue;
        ss<<kmap[code[i]];
    }
    ss>>re;
    return re;
}



int main()
{
    SubstitutionCode s;
    string key("TRADINGFEW"), code("LGXWEV");
    cout<<s.getValue(key,code)<<endl;
    return 0;
}
