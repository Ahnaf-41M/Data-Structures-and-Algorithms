#include<bits/stdc++.h>
#define  MX      10000005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
using namespace std;

int unq, NUT; //NUT = Number of Unordered Triplets
int NOT, k1, k2, k3; //NOT = Number of Ordered Triplets
bitset < MX + 5 > OK;
vector<int> primes;

void Sieve()
{
   for (int i = 3; i <= MX; i += 2)
      OK[i] = 1;
   for (int i = 3; i * i <= MX; i += 2)
      if (OK[i])
         for (int j = i * i; j <= MX; j += i)
            OK[j] = 0;
   primes.pb(2);
   for (int i = 3; i <= MX; i += 2)
      if (OK[i])
         primes.pb(i);
}
void Factorize(int n)
{
   NOT = 1, k2 = 1;

   for (int x : primes) {
      if (x * x > n)
         break;
      int cnt = 0;
      while (n % x == 0)
         cnt++, n /= x;

      k2 *= (2 * cnt + 1);
      NOT *= ((cnt + 1) * (cnt + 1) * (cnt + 1) - (cnt * cnt * cnt)); //(cnt+1)^3 - cnt^3
   }
   if (n > 1) {
      k2 *= 3;
      NOT *= 4;
   }
   k2--;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

   Sieve();
   int t;
   cin >> t;

   k1 = 1;
   for (int k = 1; k <= t; k++) {
      int n;
      cin >> n;
      Factorize(n);

      k3 = (NOT - k1 - 3 * k2) / 6;
      NUT = k1 + k2 + k3;
      cout << "NUT : " << NUT << endl;
      cout << "NOT : " << NOT << endl;
   }

   return 0;
}