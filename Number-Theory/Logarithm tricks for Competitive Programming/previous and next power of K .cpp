#include <bits/stdc++.h>

using namespace std;
// Function to return the highest power  of k less than or equal to n
int prevPowerofK(int n, int k)
{
    int p = (int)(log(n) / log(k));
    return (int)pow(k, p);
}
// Function to return the smallest power of k greater than or equal to n
int nextPowerOfK(int n, int k)
{
    return prevPowerofK(n, k) * k;
}
int main()
{
    int N = 7;
    int K = 2;

    cout << prevPowerofK(N, K) << " ";

    cout << nextPowerOfK(N, K) << endl;
    return 0;
}
