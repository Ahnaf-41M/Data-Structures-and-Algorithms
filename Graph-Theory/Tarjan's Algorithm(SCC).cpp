#include <bits/stdc++.h>
#define mx 10000
using namespace std;

vector<int> adj[mx];
stack<int> S;
int disc[mx], low[mx];
bool vis[mx];
int Timer;

void tarjanSCC(int nd,int par)
{
	disc[nd] = low[nd] = ++Timer;
	S.push(nd);
	vis[nd] = true;

	for (int v : adj[nd])
	{
		//if(v == par) continue; if the graph is undirected 
		if (!disc[v]) //check if the node is already discovered or not
		{
			tarjanSCC(v,nd);
			low[nd] = min(low[nd], low[v]);
		}
		else if (vis[v]) //check vis
			low[nd] = min(low[nd], disc[v]);
	}

	if (low[nd] == disc[nd])
	{
		while (true)
		{
			int tp = S.top(); S.pop();
			cout << " " << tp;
			vis[tp] = false; //switch vis
			if (nd == tp)
				break;
		}
		cout << endl;
	}
}
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m ; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	cout << "Strongly Connected Components are:\n";
	for (int i = 1; i <= n; i++)
		if (!disc[i])
			tarjanSCC(i,-1);


}
