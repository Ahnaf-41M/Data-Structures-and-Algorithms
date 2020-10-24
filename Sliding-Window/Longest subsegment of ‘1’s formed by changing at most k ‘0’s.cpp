#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, mx_len = 0, zero = 0, l = 0, k;
	cin >> n >> k;

	int a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (!a[i])
			zero++;
		while (zero > k) {
			if (!a[l])
				zero--;
			l++;
		}
		mx_len = max(mx_len, i - l + 1);
	}
	cout << mx_len << endl;
}