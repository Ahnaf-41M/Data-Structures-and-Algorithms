#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	int n, k;
	ll ans = 0, sum = 0;
	cin >> n >> k;
	int a[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < k; i++)
		sum += a[i];
	ans = sum;

	for (int i = k; i < n; i++) {
		sum += a[i] - a[i - k];
		ans = max(ans, sum);
	}
	cout << ans << endl;
}