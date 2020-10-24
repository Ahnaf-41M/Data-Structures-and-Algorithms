#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define pii pair<int,int>
#define inf 1000000000

vector<pair<int, int> > adj[mx];
int dis[mx], n, m;
bool vis[mx];

void Dijkstra(int nd)
{
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	Q.push({0, nd});
	dis[nd] = 0;

	while (!Q.empty())
	{
		int node = Q.top().second;
		Q.pop();

		for (auto ch : adj[node])
		{
			int x = ch.first;
			int weight = ch.second;

			if (dis[x] > dis[node] + weight) {
				dis[x] = dis[node] + weight;
				Q.push({dis[x], x});
			}

		}
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		dis[i] = inf;
	while (m--)
	{
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
	int u, v; cin >> u >> v;
	Dijkstra(u);


	cout << "Shortest path from " << u << " to " << v << " is : " << dis[v] << endl;

}
