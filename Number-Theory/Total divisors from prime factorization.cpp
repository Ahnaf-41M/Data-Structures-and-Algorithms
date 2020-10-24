#include <bits/stdc++.h>
using namespace std;
#define  LL long long
#define  MX 100005

vector<int> prime;
bool is_prime[MX + 5];

void sieve()
{
	for (int i = 3; i <= MX; i += 2)
		is_prime[i] = true;
	for (int i = 3; i <= sqrt(MX); i += 2)
		if (is_prime[i])
			for (int j = i * 2; j <= MX; j += i)
				is_prime[j] = false;
	prime.push_back(2);

	for (int i = 3; i <= MX; i += 2)
		if (is_prime[i])
			prime.push_back(i);
}
int main()
{
	sieve();

	LL n, ans = 1, i = 0;
	cin >> n;

	while (prime[i]*prime[i] <= n)
	{
		LL cnt = 0;
		while (n % prime[i] == 0)
		{
			n /= prime[i];
			cnt++;
		}
		ans *= (cnt + 1);
		i++;
	}
	if (n > 1)
		ans *= 2; //the number is a prime number

	cout << ans << endl;
}