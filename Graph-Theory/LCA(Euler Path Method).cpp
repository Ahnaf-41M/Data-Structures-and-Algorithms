#include <bits/stdc++.h>
using namespace std;
#define mx 100005

int Segtree[4 * mx];
vector<int> euler, adj[mx];
int level[mx], first_occur[mx], n;
bool vis[mx];

void DFS(int nd, int h)
{
	vis[nd] = true;
	level[nd] = h;
	first_occur[nd] = euler.size();
	euler.push_back(nd);

	for (int ch : adj[nd]) {
		if (!vis[ch]) {
			DFS(ch, h + 1);
			euler.push_back(nd);
		}
	}
}
void build(int node, int b, int e)
{
	if (b == e) {
		Segtree[node] = euler[b];
		return;
	}
	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;

	build(left, b, mid);
	build(right, mid + 1, e);

	int x = Segtree[left];
	int y = Segtree[right];

	Segtree[node] = (level[x] < level[y] ? x : y);

}
int Query(int node, int b, int e, int L, int R)
{
	if (b > R || e < L) return -1;

	if (b >= L && e <= R) return Segtree[node];

	int left = node * 2;
	int right = node * 2 + 1;
	int mid = (b + e) / 2;

	int l = Query(left, b, mid, L, R);
	int r = Query(right, mid + 1, e, L, R);

	if (l == -1) return r;
	if (r == -1) return l;

	return level[l] < level[r] ? l : r;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	euler.push_back(0); //for 1 based index

	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFS(1, 0);

	build(1, 1, 2 * n - 1);

	int q; scanf("%d", &q);

	while (q--)
	{
		int x, y; scanf("%d%d", &x, &y);
		int x1 = x, y1 = y;
		x = first_occur[x];
		y = first_occur[y];

		if (x > y) swap(x, y);

		printf("LCA of %d and %d is: %d\n", x1, y1, Query(1, 1, 2 * n - 1, x, y) );
	}
}
