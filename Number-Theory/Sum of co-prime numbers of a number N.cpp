/*For N = 10, 1,3,7,9 are co-primes of 10. Sum of 1+3+7+9 = 20.
  Ans = N*phi(N)/2. */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MX  1000005
int Phi[MX + 5];

void Totient()
{
	for (int i = 1; i <= MX; i++)
		Phi[i] = i;
	for (int i = 2; i <= MX; i++)
		if (Phi[i] == i)
			for (int j = i; j <= MX; j += i)
				Phi[j] -= Phi[j] / i;
}
signed main()
{
	Totient();
	int N; cin >> N;
	int ans = N * Phi[N] / 2;
	cout << "Sum of co-primes of " << N << ": " << ans;
}