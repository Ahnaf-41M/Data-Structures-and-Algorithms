#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Max 1000000
bool a[Max];

vector<int> v;
void sieve()
{
    ll i,j;
    a[0]=0,a[1]=0,a[2]=1;

    for(i = 3; i <= Max; i+=2)
        a[i]=1;
    for(i = 3; i < sqrt(Max); i++)
    {
        if(a[i]==1)
        {
            for(j = i*i; j <= Max; j+=i)
            {
                a[j]=0;
            }
        }
    }
    v.push_back(2);
    for(i = 3; i <= Max; i+=2)
        if(a[i])
            v.push_back(i);
}
int main()
{
    ll i,j,n;
    sieve();

    cout<<v.size()<<endl;
    cout<<"Enter a number: ";
    cin>>n;
    if(a[n])
        cout<<n<<" is a prime number\n";
    else
        cout<<n<<" is not a prime number\n";

    return 0;
}
