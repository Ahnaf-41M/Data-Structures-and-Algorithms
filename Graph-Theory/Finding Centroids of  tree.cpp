#include<bits/stdc++.h>
using namespace std;
#define mx 100005

vector<int> adj[mx], centroid;
int sz[mx], n, m;

void dfs(int nd, int par)
{
	sz[nd] = 1;
	bool is_centroid = true;

	for (int ch : adj[nd])
	{
		if (ch != par) {
			dfs(ch, nd);

			sz[nd] += sz[ch];
			if (sz[ch] > n / 2) is_centroid = false;
		}
	}
	if (n - sz[nd] > n / 2) is_centroid = false;
	if (is_centroid) centroid.push_back(nd);
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
	dfs(1, -1);
	cout << "Centroids of the tree:\n";
	for (int x : centroid)
		cout << x << " ";
}