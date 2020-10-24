#include<bits/stdc++.h>
using namespace std;

vector<int> res, adj[100];
int indeg[100];
int n, m;

void Kahn()
{
	queue<int> Q;

	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0)
			Q.push(i);
	while (!Q.empty())
	{
		int fr = Q.front();
		res.push_back(fr);
		Q.pop();

		for (auto x : adj[fr])
		{
			indeg[x]--;
			if (indeg[x] == 0)
				Q.push(x);
		}
	}
	cout << "Topological order:\n";
	for (auto x : res)
		cout << x << " ";
}
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		indeg[y]++;
	}
	Kahn();
}