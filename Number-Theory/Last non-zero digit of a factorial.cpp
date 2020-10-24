#include<bits/stdc++.h>
using namespace std;

// Initialize values of last non-zero digit of
// numbers from 0 to 9
int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

int lastNon0Digit(int n)
{
   if (n < 10)
      return dig[n];

   // Check whether tens (or second last) digit is odd or even
   // If n = 375, So n/10 = 37 and (n/10)%10 = 7
   // Applying formula for even and odd cases.
   if (((n / 10) % 10) & 1)
      return (4 * lastNon0Digit(n / 5) * dig[n % 10]) % 10;
   else
      return (6 * lastNon0Digit(n / 5) * dig[n % 10]) % 10;
}
int main()
{
   /*Let, a = floor(n/5), b = n % 5.After removing equal number of 5’s and 2’s, we can reduce the 
   problem from n! to 2^a * a! * b!. Hence, D(n) = 2^a * D(a) * D(b). Here D(n) is the last non-zero digit of n!*/
   int n;
   cin >> n;
   cout << "Last non zero digit of " << n << "! is : " << lastNon0Digit(n);
   return 0;
}
