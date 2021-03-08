#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll binomialcoeft(ll n, ll k)
{
    ll res = 1;
    if (k > n - k)
    {
        k = n - k;
    }
    for (ll i = 0; i < k; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;

}
int main()
{
    ll n, k;
    while (cin >> n >> k)
    {
        cout << binomialcoeft(n, k) << endl;
    }
}
