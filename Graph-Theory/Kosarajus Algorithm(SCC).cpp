#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000], revAdj[1000], components;
stack<int> S;
int n, m;
bool vis[1000];

void dfs1(int nd)
{
	vis[nd] = true;

	for (int ch : adj[nd])
		if (!vis[ch])
			dfs1(ch);
	S.push(nd);
}

void dfs2(int nd)
{
	vis[nd] = true;
	components.push_back(nd);
	for (int ch : revAdj[nd])
		if (!vis[ch])
			dfs2(ch);

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
		revAdj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs1(i);
	memset(vis, false, sizeof(vis));

	cout << "Strongly connected components are:\n";

	while (!S.empty())
	{
		int tp = S.top(); S.pop();
		if (!vis[tp])
		{
			dfs2(tp);
			for (int i = 0; i < components.size(); i++)
				cout << components[i] << " ";
			cout << endl;
			components.clear();
		}
	}

}
