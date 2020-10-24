#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n = 12,SOD = 0,i;

    for(i = 1; i <= sqrt(n); i++)
    {
        if(n%i == 0)
        {
            if(n/i == i)
                SOD += i;
            else
            {
                SOD += i;
                SOD += n/i;
            }
        }
    }
    //including 1 and n itself
    cout<<"Sum of divisors of "<<n<<" is: "<<SOD<<endl;
}
