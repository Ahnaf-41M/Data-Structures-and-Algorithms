#include<bits/stdc++.h>
using namespace std;
// Returns largest power of p that divides n!
int largestPower(int n, int p)
{
    int x = 0;

    // Calculate x = n/p + n/(p^2) + n/(p^3) + ....
    while (n)
    {
        n /= p;
        x += n;
    }
    return x;
}
int main()
{
    int n = 10, p = 3;
    printf("The largest power of %d that divides %d! is %d\n",p, n, largestPower(n, p));
    return 0;
}
