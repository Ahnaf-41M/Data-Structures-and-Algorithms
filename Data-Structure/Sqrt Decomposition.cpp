/*Minimum element in a range [L...R]*/
#include<bits/stdc++.h>
using namespace std;

int n, m, blk_len, l, r;
vector<int> V, a;

int getMin()
{
	int LB = l / blk_len;
	int RB = r / blk_len;
	int mn = INT_MAX;

	if (LB == RB)
	{
		for (int i = l; i <= r; i++)
			mn = min(a[i], mn);
	}
	else
	{
		for (int i = l; i < blk_len * (LB + 1); i++)
			mn = min(a[i], mn);
		for (int i = LB + 1; i < RB; i++)
			mn = min(V[i], mn);
		for (int i = blk_len * RB; i <= r; i++)
			mn = min(a[i], mn);
	}
	return mn;
}
void pre_process()
{
	int i, j = 0, mn = INT_MAX;
	int len = (n + blk_len - 1) / blk_len;
	V.assign(len, INT_MAX);

	for (i = 0; i < n; i++)
	{
		if (i % blk_len == 0 && i != 0) {
			V[++j] = a[i];
		}
		else
			V[j] = min(a[i], V[j]);

	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a.push_back(x);
	}

	blk_len = sqrt(n);

	pre_process();
	while (m--)
	{
		cin >> l >> r;
		cout << getMin() << endl;
	}
}