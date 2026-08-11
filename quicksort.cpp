#include<bits/stdc++.h>
using namespace std;

int quicksort(vector<int> &v ,int low,int high){
    int part=v[low];
    int i=low;
    int j=high;
    while (i<j)
    {
        while (i<high && part>=v[i])
        {
            i++;
        }
        while (j> low&& part<v[j])
        {
            j--;
        }
        if(i<j)
        swap(v[i], v[j]);
   }
    swap(v[j], v[low]);
    return j;
}

void qs(vector<int> &v ,int low,int high){
if(low>=high)
return;
int part=quicksort(v,low,high);
qs(v,low,part-1);
qs(v,part+1,high);
}


int main()
{
vector<int>v={0,4,1,2,9,100,6,2};
qs(v,0,v.size()-1);
for(int i=0;i<v.size();i++)
{
    cout<<v[i]<<" ";
}

return 0;
}