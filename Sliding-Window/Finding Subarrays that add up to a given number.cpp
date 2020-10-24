/*Only for positive numbers.*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, req_sum, cur_sum = 0, left = 0;
	cin >> n >> req_sum;

	int a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		cur_sum += a[i];
		while (cur_sum > req_sum) {
			cur_sum -= a[left];
			left++;
		}
		if (cur_sum == req_sum) {
			cout << "[" << left << "," << i << "] is a subarray\n";
		}

	}
}