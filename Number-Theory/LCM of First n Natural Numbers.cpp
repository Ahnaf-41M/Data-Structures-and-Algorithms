#include<bits/stdc++.h>

#define pb push_back
#define ll long long
#define mx 9000000
using namespace std;

vector<ll> v;
bool isprime[mx];
void sieve()
{
    ll i,j;
    isprime[2]=true;

    for(i = 3; i <= mx; i+=2)
        isprime[i]=true;
    for(i = 2; i*i <= mx; i++)
    {
        if(isprime[i])
        {
            for(j = 2; i*j <= mx; j++)
            {
                isprime[j*i]=false;
            }
        }
    }
    v.pb(2);
    for(i = 3; i <= mx; i+=2)
        if(isprime[i])
            v.pb(i);

}
ll LCM(ll n)
{
    ll p = 1;
    ll lm  = 1;

    for(int i = 0; i<v.size(),v[i]<=n; i++)
    {
        p=v[i];
        while(p*v[i]<=n)
            p*=v[i];
        lm*=p;
        lm%=1000000007;
    }
    return lm;
}
int main()
{
    sieve();

    ll n;
    cin>>n;
    cout<<LCM(n);

    return 0;
}





