#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, req_sum, cur = 0;
	map<int, int> mp;

	cin >> n >> req_sum;
	int a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		cur += a[i];

		if (cur == req_sum) {
			cout << "Sum found between indexes 0 to " << i << endl;
		}
		if (mp.find(cur - req_sum) != mp.end()) {
			cout << "Sum found between indexes " << mp[cur - req_sum] + 1 << " to " << i << endl;
		}
		mp[cur] = i;
	}
}