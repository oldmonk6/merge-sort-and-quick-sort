#include<iostream>
using namespace std;
int partition( int arr[],int si,int ei)
{
    int pivotele=arr[(si+ei)/2];
    int count =0;
    for (int i=si;i<=ei;i++)
    {
        if(i==(si+ei)/2) continue;
        if(arr[i]<=pivotele) count++;
    }
    int pivotidx=count+si;
    swap(arr[(si+ei)/2],arr[pivotidx]);
    int i=si;
    int j=ei;
    while(i<pivotidx && j>pivotidx)
    {
       if(arr[i]<=pivotele)i++;
       if(arr[j]>pivotele)j--;
       else if(arr[i]>pivotele && arr[j]<=pivotele)
       {
          swap(arr[i],arr[j]);
          i++;
          j--;
       }
    }
    return pivotidx;
    

}
int kthsmallele(int arr[],int si,int ei,int k)
{
    
    int pi=partition(arr,si,ei);
    if(pi+1==k)return arr[pi];
    else if(pi+1<k) return kthsmallele(arr,pi+1,ei,k);
    else return kthsmallele(arr,si,pi-1,k);
   
}
int main()
{
    int arr[]={5,1,8,2,7,6,3,4,-8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    cout<<kthsmallele(arr,0,n-1,k);
  
}