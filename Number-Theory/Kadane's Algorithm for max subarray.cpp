#include<bits/stdc++.h>
using namespace std;

int Kadanes(int n,int a[],int max_global,int max_current)
{
     max_global=max_current=a[0];
     int i;

     for(i = 1; i < n; i++)
     {
         max_current = max(a[i],max_current+a[i]);
         if(max_global<max_current)
            max_global=max_current;
     }
     return max_global;


}

int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int a[n];

    int i,max_global,max_current;

    for(i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"Maximum sum of the sub-array: "<<Kadanes(n,a,max_global,max_current)<<endl;
    return 0;
}
