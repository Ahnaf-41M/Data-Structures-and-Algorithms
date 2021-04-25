/*For the nth Catalan number = [ (2nCn)/(n+1) ].. O(n) solve*/
#include<bits/stdc++.h>
using namespace std;

unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{
    unsigned long int res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
unsigned long int catalan(unsigned int n)
{
    unsigned long int c = binomialCoeff(2 * n, n); //2nCn
    return c / (n + 1); //(2nCn)/(n+1)
}

int main()
{
    for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";
    return 0;
}

