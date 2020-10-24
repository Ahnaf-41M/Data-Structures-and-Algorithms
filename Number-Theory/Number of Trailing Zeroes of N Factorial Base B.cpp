#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MX 1000000
vector<LL> primes;
bool is_prime[MX + 5];

void sieve()
{
   for (int i = 3; i <= MX; i += 2)
      is_prime[i] = true;
   for (int i = 3; i <= sqrt(MX); i += 2)
      if (is_prime[i])
         for (int j = i * 2; j <= MX; j += i)
            is_prime[j] = false;
   primes.push_back(2);
   for (int i = 3; i <= MX; i += 2)
      if (is_prime[i])
         primes.push_back(i);
}
LL Highest_Power(LL n, LL p)
{
   LL res = 0, N = n;

   while (N)
   {
      res += (N / p);
      N /= p;
   }
   return res;
}
// Returns largest power of base that divides n!
LL Trailing_Zero_Base_b(LL n, LL base)
{
   LL ans = INT_MAX;
   for (int i = 0; i < primes.size(), primes[i] <= base; i++)
   {
      if (base % primes[i] == 0)
      {
         int freq = 0;
         while (base % primes[i] == 0) {
            freq++;
            base /= primes[i];
         }
      //highest power of primes[i] that divides n!
         LL Power = Highest_Power(n, primes[i]);
         ans = min(ans, Power / freq);
      }
   }
   return ans;
}
int main()
{
   sieve();

   LL n, base;

   cin >> n >> base;

   LL res = Trailing_Zero_Base_b(n, base);

   cout << "Trailing zeroes in " << n << "! in base " << base << " is: " << res << endl;
}
