#include<bits/stdc++.h>
using namespace std;
#define mx 100000
int a[mx];

void finddiv()
{
    int i,j;

    for(i = 1; i <= mx; i++)
    {
        for(j = i; j <= mx; j+=i)
        {
            a[j]++;
        }
    }
}
int main()
{
    finddiv();
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    for(int i = 1; i <= n; i++)
        cout<<"Divisors of "<<i<<" : "<<a[i]<<endl;
}
