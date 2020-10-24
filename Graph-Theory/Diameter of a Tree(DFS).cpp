#include<bits/stdc++.h>
using namespace std;
#define mx 100005

vector<int> adj[mx];
int n, m, node, cur;
bool vis[mx];

void dfs(int nd, int cnt)
{
	vis[nd] = true;
	if (cnt > cur)
	{
		node = nd; cur = cnt;
	}
	for (int ch : adj[nd])
		if (!vis[ch])
			dfs(ch, cnt + 1);
}
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> n >> m;

	while (m--)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, 0);
	cur = 0;
	int st = node;

	for (int i = 1; i <= n; i++)
		vis[i] = false;
	dfs(node, 0);

	cout << "Starting node is " << st << " and end node is " << node << endl;
	cout << "length is " << cur << endl;
}