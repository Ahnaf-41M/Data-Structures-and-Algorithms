#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
ll phi[mx];
ll res[mx];

void phi_find()
{
    ll i,j;
    phi[1]=1;
    for(i = 2; i <= mx; i++)
        phi[i]=i;
    for(i = 2; i < mx; i++)
    {
        if(phi[i]==i)
        {
            for(j = i; j <= mx; j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }

}
void sumOfGcd()
{
    ll i,j;
    phi_find();
    for(i = 1; i <= mx; i++)
    {
        for(j = 2; i*j <= mx; j++)
        {
            res[i*j]+=i*phi[j];
        }
    }
    for(i = 2; i <= mx; i++)
    {
        res[i]+=res[i-1];
    }
}
int main()
{
    sumOfGcd();
    ll n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Sum of gcd from 1 upto "<<n<<" : "<<res[n]<<endl;
}


