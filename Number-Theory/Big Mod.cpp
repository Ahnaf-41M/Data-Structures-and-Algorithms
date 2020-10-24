#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll bigmod(ll n,ll p,ll m)
{
    if(p==0)
        return 1;
    if(p%2==0)
    {
        ll ret = bigmod(n,p/2,m);
        return (ret%m)*(ret%m)%m;
    }
    else
    {
        return (n%m)*((bigmod(n,p-1,m))%m)%m;
    }
}
int main()
{
    ll n,p,m;

    cout<<"Enter n,p and m: ";
    cin>>n>>p>>m;
    cout<<bigmod(n,p,m)<<endl;
}

