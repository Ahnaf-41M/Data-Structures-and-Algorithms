#include <bits/stdc++.h>
using namespace std;
#define MX 100005
vector<int> adj[MX];
bool vis[MX];
int low[MX], disc[MX], AP[MX];

void DFS(int nd, int par)
{
   static int Time = 0;

   disc[nd] = low[nd] = ++Time;
   vis[nd] = true;
   int child = 0;

   for (auto ch : adj[nd])
   {
      if (!vis[ch])
      {
         child++; //child of nd
         DFS(ch, nd);

         /*low[nd] indicates earliest visited vertex
         (the vertex with minimum discovery time) that can be reached from
         subtree rooted with nd. A node nd is head if disc[nd] = low[nd].*/


         /*Check if the subtree rooted with ch has a connection to
         one of the ancestors of nd */
         low[nd] = min(low[ch], low[nd]);

         // (1) nd is root of DFS tree and has two or more chilren.
         if (par == -1 && child > 1)
            AP[nd] = 1;
         /* (2) If nd is not root and low value of one of its child is more
            than or equal to discovery value of nd.*/
         if (par != -1 && low[ch] >= disc[nd])
            AP[nd] = 1;

      }
      else if (ch != par)
         low[nd] = min(low[nd], disc[ch]);
   }
}
int main()
{
   int n, m, i;
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

   cin >> n >> m;

   for (i = 0; i < m; i++)
   {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
   for (i = 1; i <= n; i++)
      if (!vis[i])
         DFS(i, -1);
   cout << "Articulation points in this graph:\n";
   for (i = 1; i <= n; i++)
      if (AP[i])
         cout << i << " ";
}
