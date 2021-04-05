//Suppose n=3, sum = gcd(1,2) + gcd(2,3) + gcd(1,3)
#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define int long long

int phi[MAX + 5], result[MAX + 5];

void computeTotient()
{
   for (int i = 1; i <= MAX; i++)
      phi[i] = i;
   for (int i = 2; i <= MAX; i++)
      if (phi[i] == i)
         for (int j = i; j <= MAX; j += i)
            phi[j] -= phi[j] / i;
}
void sumOfGcdPairs()
{   
   for (int i = 1; i <= MAX; i++) {
      /* If d is a divisorof N, then the number of pairs (a,N),
      where (1<=a<=N), such that GCD(a, N) = d is phi[N/d]. */
      for (int j = 2*i; j <= MAX; j += i) {
         result[j] += i * phi[j / i];
      }
   }
   // Add summation of previous calculated sum
   for (int i = 2; i <= MAX; i++)
      result[i] += result[i - 1];
}
signed main()
{
   computeTotient();
   sumOfGcdPairs(); // Function to calculate sum of all the GCD pairs

   int N = 4;
   cout << "Summation of " << N << " = " << result[N] << endl;;
   N = 12;
   cout << "Summation of " << N << " = "  << result[N] << endl;
   N = 5000;
   cout << "Summation of " << N << " = " << result[N] ;
}
