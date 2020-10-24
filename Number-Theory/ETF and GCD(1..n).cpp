/*Number of integers having GCD d with n,equals to the
Number of co-prime with n/d(means phi[n/d]*/

/*Suppose n=4,we have to find ans = gcd(1,4)+ gcd(2,4)+ gcd(3,4)+ gcd(4,4)*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
#define ll long long

int phi[MAX];
void find_phi()
{
    int i,j;
    for(i=2; i<=MAX; i++)
        phi[i]=i;
    for(i=2; i<=MAX; i++)
    {
        if(phi[i]==i)
        {
            for(j=i; j<=MAX; j+=i)
                phi[j]-=phi[j]/i; //Inclusion_Exclusion Law used
        }
    }
}
int main()
{
    int t,n;
    find_phi();
    ll res= 0;

    cin>>t;

    while(t--)
    {
        cin>>n;
        int d1,d2;
        for(int i = 1; i*i <= n; i++)
        {
            if(i==1) /*  as phi[1]=0 (this is a corner case)  */
            {
                res += phi[n/i];
                res += n;     /*  as gcd(n,n)==n  */
            }
            else if(n%i==0)
            {
                d1 = i;
                d2 = n/i;

                if(d1==d2)
                    res += (d1*phi[n/d1]);
                else
                {
                    res += (d1*phi[n/d1]);
                    res += (d2*phi[n/d2]);
                }
            }
        }
        cout<<res<<endl;
        res=0;
    }
}
