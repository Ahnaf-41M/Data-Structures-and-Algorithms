/*This approach finds a^n in using log(n) complexity*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll Binary_Expo(ll a,ll n)
{
     ll res = 1;

     while(n>0)
     {
          if(n&1)
               res = res * a;
          a=a*a;
          n>>=1; /* n = n/2*/
     }
     return res;
}
int main()
{
     ll a,n;
     cout<<"Enter a and n: ";
     cin>>a>>n;

     cout<<a<<"^"<<n<<" is "<<Binary_Expo(a,n)<<endl;
}
