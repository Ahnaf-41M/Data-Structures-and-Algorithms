#include <bits/stdc++.h>
using namespace std;

double kthRoot(double n, int k)
{
    return pow(k,(1.0 / k)*(log(n)/ log(k)));
}
int main()
{
    double N = 8.0;
    int K = 3;

    cout << kthRoot(N, K);

    return 0;
}
