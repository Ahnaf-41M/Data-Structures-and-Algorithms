#include <bits/stdc++.h>
using namespace std;
#define MX 100005
int n, m;
int cost[MX], parent[MX];
vector<int> adj[MX];

void bfs()
{
   queue<int> q;
   q.push(1);
   cost[1] = 0;
   parent[1] = -1;
   while (!q.empty())
   {
      int cur = q.front();
      q.pop();

      for (int ch : adj[cur]) {
         if (cost[ch] == -1) {
            q.push(ch);
            cost[ch] = cost[cur] + 1;
            parent[ch] = cur;
         }
      }
   }
}

int main()
{

   memset(cost, -1, sizeof cost);

   cin >> n >> m;

   for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
   bfs();
}
