#include<bits/stdc++.h>
using namespace std;
#define mx 1000
#define pb push_back

const int sz = log2(mx);
vector<int> adj[mx];
vector<vector<int> > LCA;
int level[mx + 5], parent[mx+5];
int n, q, len;

void init()
{
	LCA.assign(n+1,vector<int> (len+1));
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= len; j++)
			LCA[i][j] = -1;
}
void dfs(int nd, int par)
{
	LCA[nd][0] = par;
	for (int ch : adj[nd])
	{
		if (ch != par)
		{
			level[ch] = level[nd] + 1;
			parent[ch] = nd;
			dfs(ch, nd);
		}
	}
}
void buildLCA()
{
	dfs(1, -1);

	for (int j = 1; j <= len; j++)
	{
		for (int i = 1;  i <= n; i++)
		{
			if (LCA[i][j - 1] != -1)
			{
				int pp = LCA[i][j - 1];
				LCA[i][j] = LCA[pp][j - 1];
			}
		}
	}
}
int findLCA(int a, int b)
{
	if (level[b] < level[a]) swap(a, b);

	int d = level[b] - level[a];
	while (d > 0)
	{
		int i = log2(d);
		b = LCA[b][i];
		d -= (1 << i);
	}

	if (a == b) return a;

	for (int i = len; i >= 0; i--)
		if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
			a = LCA[a][i], b = LCA[b][i];
	return parent[a];
}
int getDis(int a, int b)
{
	int lca = findLCA(a, b);
	return level[a] + level[b] - 2 * level[lca];
}
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> n >> q; len = log2(n);

	init();
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].pb(y); adj[y].pb(x);
	}
	buildLCA();

	while (q--)
	{
		int a, b; cin >> a >> b;
		cout << getDis(a, b) << endl;
	}

}