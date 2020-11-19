#include<bits/stdc++.h>
using namespace std;
#define mx 100005

vector<int> adj[mx];
vector<vector<int> > LCA;
int par[mx], lev[mx];
int n, m, q, sz;
bool vis[mx];

void dfs(int nd, int pr)
{
	LCA[nd][0] = pr;
	for (int ch : adj[nd])
		if (ch != pr)
		{
			par[ch] = nd;
			lev[ch] = lev[nd] + 1;
			dfs(ch, nd);
		}

}
void buildLCA()
{
	for (int j = 1; j <= sz; j++)
	{
		for (int i = 1; i <= n; ++i)
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
	if (lev[a] > lev[b])
		swap(a, b);
	int d = lev[b] - lev[a];

	while (d > 0)
	{
		int i = log2(d);
		b = LCA[b][i];
		d -= (1 << i);
	}
	if (a == b) return a;

	for (int i = sz; i >= 0; i--)
		if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
			a = LCA[a][i], b = LCA[b][i];
	return par[a];
}
void init()
{
	sz = log2(n);
	LCA.assign(n + 1, vector<int>(sz + 1));
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= sz; j++)
			LCA[i][j] = -1;

	for (int i = 0; i < m; ++i)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m >> q;

	init();
	dfs(1, -1);
	buildLCA();

	while (q--)
	{
		int x, y; cin >> x >> y;
		cout << "LCA(" << x << "," << y << "): " << findLCA(x, y) << endl;
	}

}
