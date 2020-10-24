#include <bits/stdc++.h>
using namespace std;
#define mx 1000

vector<int> adj[mx];
int n, m;
int parent[mx], cycle_start, cycle_end, color[mx];
bool ok = true;

void dfs(int nd, int par)
{
	color[nd] = 1;

	for (int ch : adj[nd])
	{
		if (!color[ch])
		{
			parent[ch] = nd;
			dfs(ch, nd);
		}
		else if (ch != par && color[ch] == 1) {
			ok = false;
			cycle_start = ch;
			cycle_end = nd;
			break;
		}

	}
	if (!ok) return;
	color[nd] = 2;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ok = true;

	cin >> n >> m;

	while (m--) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		if (!color[i])
			dfs(i, parent[i]);
	if (ok) cout << "Acyclic\n";
	else {
		vector<int> ans;
		ans.push_back(cycle_start);

		for (int i = cycle_end; i != cycle_start; i = parent[i])
			ans.push_back(i);
		ans.push_back(cycle_start);
		reverse(ans.begin(), ans.end());

		for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

	}


}