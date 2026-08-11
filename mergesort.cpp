#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v,int low,int mid ,int high)
{
int left =low;
int right=mid+1;
vector<int> temp;
while(left<=mid && right <=high)
{
    if(v[left]<=v[right]){
    temp.push_back(v[left]);
        left++;
    }
    else 
    {
    temp.push_back(v[right]);
    right++;
     }

}
while (left<=mid)
{
     temp.push_back(v[left]);
     left++;
}
while(right<=high)
{
    temp.push_back(v[right]);
    right++;
}

for(int i=low; i<=high; i++)
{
    v[i] = temp[i-low];
}
}
void mergesort(vector<int> & v,int low, int high)
{
    if(low>=high)
    return;
    int mid=(low+high)/2;
    mergesort(v,low,mid);
    mergesort(v,mid+1,high);
    merge(v,low,mid,high);

}
int main()
{
    vector<int>v={0,5,9,1,4,8,3};
   
    mergesort(v,0,v.size()-1);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;

}
