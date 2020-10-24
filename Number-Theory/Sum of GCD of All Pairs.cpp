//Suppose n=3, sum = gcd(1,2) + gcd(2,3) + gcd(1,3)
#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

// phi[i] stores euler totient function for i result[j] stores result for value j
long long phi[MAX], result[MAX];

// Precomputation of phi[] numbers
void computeTotient()
{
    phi[1] = 1;
    for (int i=2; i<MAX; i++)
    {
        if (!phi[i])
        {
            phi[i] = i-1;
            for (int j = (i<<1); j<MAX; j+=i)
            {
                if (!phi[j])
                    phi[j] = j;
                phi[j] = (phi[j]/i)*(i-1);
            }
        }
    }
}
// Precomputes result for all numbers till MAX
void sumOfGcdPairs()
{
    // Precompute all phi value
    computeTotient();
    for (int i=1; i<MAX; ++i)
    {
        // Iterate through all the divisors of i.
        for (int j=2; i*j<MAX; ++j)
            result[i*j] += i*phi[j];
    }
    // Add summation of previous calculated sum
    for (int i=2; i<MAX; i++)
        result[i] += result[i-1];
}
int main()
{
    // Function to calculate sum of all the GCD pairs
    sumOfGcdPairs();

    int N = 4;
    cout << "Summation of " << N << " = " << result[N] << endl;;
    N = 12;
    cout << "Summation of " << N << " = "  << result[N] << endl;
    N = 5000;
    cout << "Summation of " << N << " = "<< result[N] ;
}

