#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)
{
    return (ceil(log2(n)) == floor(log2(n)));
}
int main()
{
    int N = 8;

    if (isPowerOfTwo(N))
        cout << "Yes";
    else
        cout << "No";
}
