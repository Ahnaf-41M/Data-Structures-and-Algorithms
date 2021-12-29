#include<bits/stdc++.h>
using namespace std;
#define MX 50000
bool OK[MX];
vector<int> v;

void Sieve()
{
    for (int i = 3; i < MX; i += 2)
        OK[i] = 1;
    for (int i = 3; i * i < MX; i++)
        if (OK[i])
            for (int j = i * i; j < MX; j += i)
                OK[j] = 0;

    v.push_back(2);
    for (int i = 3; i < MX; i += 2)
        if (OK[i])
            v.push_back(i);
}
int main()
{
    Sieve();
    int n;
    cin >> n;
    if (OK[n]) cout << n << " is a prime number\n";
    else cout << n << " is not a prime number\n";

    return 0;
}
