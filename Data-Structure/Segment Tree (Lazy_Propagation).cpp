#include<bits/stdc++.h>
using namespace std;
#define mx 100005

struct info
{
	int sum; int prop;
} tree[4 * mx];
int a[mx], i, j, n, q;

void build(int node, int b, int e)
{
	if (b == e)
	{
		tree[node].sum = a[b];
		return;
	}
	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;

	build(left, b, mid);
	build(right, mid + 1, e);

	tree[node].sum = tree[left].sum + tree[right].sum;
}
void update(int node, int b, int e, int i, int j, int x)
{
	if (b > j || e < i)
		return;
	if (b >= i && e <= j)
	{
		tree[node].sum += ((e - b + 1) * x);
		tree[node].prop += x;
		return;
	}
	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;

	update(left, b, mid, i, j, x);
	update(right, mid + 1, e, i, j, x);

	tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;
}
int query(int node, int b, int e, int i, int j, int carry)
{
	if (i > e || j < b)
		return 0;
	if (i <= b && e <= j)
		return tree[node].sum + (e - b + 1) * carry;
	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;

	int p1 = query(left, b, mid, i, j, carry + tree[node].prop);
	int p2 = query(right, mid + 1, e, i, j, carry + tree[node].prop);

	return p1 + p2;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	while (q--)
	{
		char type; cin >> type;
		if (type == 'U')
		{
			int x; cin >> i >> j >> x;
			update(1, 1, n, i, j, x);
		}
		else
		{
			cin >> i >> j;
			cout << query(1, 1, n, i, j, 0) << endl;
		}
	}
}