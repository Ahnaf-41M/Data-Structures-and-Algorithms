#include<bits/stdc++.h>
using namespace std;
#define MX 100005
int n, m;
vector<int> adj[MX];
int low[MX], disc[MX], vis[MX];
int timer = 0;
void DFS(int nd, int par)
{
   vis[nd] = 1;
   disc[nd] = low[nd] = ++timer;

   for (int ch : adj[nd])
   {
      if (!vis[ch])
      {
         DFS(ch, nd);
         low[nd] = min(low[nd], low[ch]);
         if (low[ch] > disc[nd])
            cout << ch << "-" << nd << " is a bridge\n";
      }
      else if (ch != par)
         low[nd] = min(low[nd], disc[ch]);
   }
}
int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
   cin >> n >> m;

   while (m--)
   {
      int x, y; cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }

   DFS(1, -1);
}
