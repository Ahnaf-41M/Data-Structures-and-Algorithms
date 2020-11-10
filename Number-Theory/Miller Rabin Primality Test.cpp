#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define ull unsigned long long int

ll mulmod(ll a, ll b, ll c) //calculates (a*b)%c
{
	ll x = 0, y = a % c;
	while (b)
	{
		if (b & 1)
			x = (x + y) % c;
		y = (y * 2ll) % c;
		b >>= 1;
	}
	return x;
}

ll Power(ll a, ll d, ll n) //calculates (a^d) % n
{
	ll res = 1;
	a %= n; //Update a if it is more than or equal to n

	while ( d ) {
		if (d & 1)
			res = mulmod(res, a, n);
		d >>= 1;
		a = mulmod(a, a, n);
	}
	return res;
}
bool check_composite(ll n, ll a, ll d, ll s)
{
	ll x = Power(a, d, n); //a^d % n

	if (x == 1 || x == n - 1) //means it's a prime number
		return false;

	for (int j = 1; j < s; j++) {
		x = mulmod(x, x, n);
		if (x == n - 1) //means it's a prime number
			return false;
	}
	return true;
}
bool Miller_Rabin(ll n)
{
	if (n < 4)
		return n == 2 || n == 3;
	ll s = 0;
	ll d = n - 1; //2^s * d = n-1

	while ( d % 2 == 0)
		d >>= 1, s++;

	for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n == a)
			return true;
		if (check_composite(n, a, d, s))
			return false;
	}
	return true;
}
int main()
{
	ll n; cin >> n;
	if (Miller_Rabin(n))
		cout << n << " is a prime number\n";
	else
		cout << n << " is not a prime number\n";

}