#include <bits/stdc++.h>
using namespace std;

int val, n;

int SubSize(int a[])
{
	int mn_len = n;
	int cnt = 0, left = 0, cur_sum = 0;

	for (int i = 0; i < n; i++) {
		cur_sum += a[i];
		if (cur_sum >= val) {
			mn_len = min(mn_len, i - left + 1);
			while (cur_sum - a[left] >= val) {
				cur_sum -= a[left];
				left++;
			}
			if (cur_sum >= val) {
				cur_sum -= a[left];
				mn_len = min(mn_len, i - left + 1);
				left++;
			}
		}
	}
	return mn_len;
}
int main()
{
	cin >> n >> val;
	int a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << "Smallest sub-array size: " << SubSize(a) << endl;
}