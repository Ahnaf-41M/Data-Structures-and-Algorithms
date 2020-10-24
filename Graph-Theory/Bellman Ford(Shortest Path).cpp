#include <bits/stdc++.h>
using namespace std;
#define MX  100005
#define ff  first
#define ss  second

vector<pair<int, int> > adj[MX];
bool vis[MX];
int n, m, par[MX], dis[MX];

void BellmanFord()
{
	dis[0] = 0; //source distance should be zero
	int x = -1;
	for (int i = 0; i < n; i++) {
		x = -1;
		for (int j = 0; j < n; j++) {
			for (auto ch : adj[j]) {
				int u = j, v = ch.ff, w = ch.ss;
				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					x = u;
				}
			}
		}
	}
	if (x == -1) {
		cout << "Vertex:\tDistance from source:\n";
		for (int i = 0; i < n; i++) {
			cout << i << "\t" << dis[i] << endl;
		}
	}
	else  cout << "Graph contains cycle.\n";
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) dis[i] = 1e9;
	while (m--) {
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
	}
	BellmanFord();
}
