#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 100005

bool is_prime[MX + 5];
vector<ll> primes;
ll n, m;
inline void sieve()
{
	for (ll i = 3; i <= MX; i += 2)
		is_prime[i] = true;
	for (ll i = 3; i <= sqrt(MX); i += 2)
		if (is_prime[i])
			for (ll j =  i * 2; j <= MX; j += i)
				is_prime[j] = false;
	primes.push_back(2);
	for (ll i = 3; i <= MX; i += 2)
		if (is_prime[i])
			primes.push_back(i);
}
ll Sum_of_Divisors()
{
	/*Sum of divisors = (1 + p1 + p1^2 ... p1^a1) * (1 + p2 + p2^2 ... p2^a2) *.................
	  ....................*(1 + pk + pk^2 ... pk^ak). p denotes prime number. */
	ll root = sqrt(n), Sum = 1;
	for (ll i = 0; i < primes.size() && primes[i] <= n; i++) {
		if ( n % primes[i] == 0 ) {
			ll cur_term = 1;
			ll cur_sum = 1;

			while ( n % primes[i] == 0 )
			{
				n /= primes[i];
				cur_term *= primes[i]; //p^1,p^2,p^3...
				cur_sum += cur_term;   //1+p^1+p^2+...
			}
			Sum *= cur_sum;
		}
	}
	return Sum;
}
int main()
{
	sieve();
	cin >> n;
	cout << Sum_of_Divisors() << endl;
}
