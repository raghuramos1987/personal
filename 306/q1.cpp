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

class PackingParts
{
    public:
        int pack(vector <int> partSizes, vector <int> boxSizes);
};

int PackingParts::pack(vector <int> partSizes, vector <int> boxSizes)
{
    int j,i=0;
    int count = 0;
    int psize = partSizes.size();
    int bsize = boxSizes.size();
    j=0;
    for(j=0;j<bsize;j++)
    {
        if(i>=psize)
            break;
        while(1)
        {
            if(boxSizes[i++]>=partSizes[j])
            {
                count++;
                break;
            }
        }
    }
    return count;
}

int main()
{
    PackingParts p;
    int al[] = {1,1,1,1};
    int bl[] = {1,2,2,3,6,7};
    vector<int> all(al,al+4);
    vector<int> bll(al,al+6);
    cout<<p.pack(all,bll)<<endl;
    return 0;
}

