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


class BinarySearchable
{
    public:
        int howMany(vector <int> sequence);
};

int BinarySearchable::howMany(vector <int> sequence)
{
    int count=0;
    int i;
    int size = sequence.size();
    vector<int> min(size,-10001), max(size, 10001);
    min[0] = sequence[0];
    max[size-1] = sequence[size-1];
    for(i=1;i<size;i++)
    {
        min[i] = (min[i-1]<sequence[i])? sequence[i] : min[i-1];
    }
    for(i=size-2;i>=0;i--)
    {
        max[i] = (max[i+1]>sequence[i])? sequence[i] : max[i+1];
    }
    for(i=0;i<size;i++)
    {
        cout<<max[i]<<" "<<min[i]<<endl;
    }
    for(i=0;i<size;i++)
    {
        if((sequence[i] <= max[i])&&(sequence[i] >= min[i]))
        {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
int main()
{
    BinarySearchable s;
    int al[] = { 1, 5, 7, 11, 12, 18 };
    vector<int> all(al,al+6);
    cout<<all.size()<<endl;
    string cur("999");
    s.howMany(all);
    return 0;
}
