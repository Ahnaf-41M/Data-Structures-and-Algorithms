#include<bits/stdc++.h>
using namespace std;
#define MAX 31622 /*sqrt of 10^9*/
#define ll long long

vector<ll> primes;

void sieve()
{
    int i,j;
    bool isPrime[MAX+5];

    for(i = 2; i < MAX; i++)
        isPrime[i] = true;

    for(i = 3; i <= sqrt(MAX); i+=2)
    {
        if(isPrime[i])
        {
            for(j = i*i; j <= MAX; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
    primes.push_back(2);
    for(i = 3; i <= MAX; i+=2)
        if(isPrime[i])
            primes.push_back(i);

}
void SegmentedSieve(ll l,ll r)
{
     bool isPrime[r-l+1];
     for(int i = 0; i < r-l+1; i++)
          isPrime[i] = true;

     if(l==1) isPrime[0] = false;

     for(int i = 0; primes[i]*primes[i] <= r; i++)
     {
          ll current_prime = primes[i];
          ll base = (l/current_prime)*current_prime;

        /*Suppose l=21 and current_prime = 2 then we will start from base = (21/2)*2 = 20,
          But 20 is in the left of l,so we need to add current_prime to base(which is 2
          in this case*/

          if(base < l)
               base+=current_prime;

          for(ll j = base; j <= r; j+=current_prime)
          {
               isPrime[j-l] = false; //isPrime[21-21] = false ,in case curprime=3
          }
          /*Suppose base=5,which is a prime number.But according to the loop we are assigning as false.
            So we need to assign it as true.. */
          if(base == current_prime)
               isPrime[base-l] = true;
     }

     /*printing primes in the range (l,r)*/

     for(int i = 0;i < r-l+1; i++ )
     {
          if(isPrime[i])
               cout<<(i+l)<<endl;
     }

}
int main()
{
    sieve();
    int t;
    ll l,r;
    cin>>t;

    while(t--)
    {
         cin>>l>>r;
         SegmentedSieve(l,r);
    }
}
