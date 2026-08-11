#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(arr[mini]>arr[j])
            {
               mini=j;
            }
        }
            int temp=arr[mini];
            arr[mini]=arr[i];
            arr[i]=temp;
        
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}