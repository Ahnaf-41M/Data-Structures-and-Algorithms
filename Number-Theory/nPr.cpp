#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll nPr(ll n,ll r)
{
    ll i,p=1;

    for(i = 0; i < r; i++)
    {
        p*=(n-i);
    }
    return p;
}
int main()
{
    ll n,r;

    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter r: ";
    cin>>r;

    cout<<n<<"P"<<r<<" is : "<<nPr(n,r)<<endl;
}
