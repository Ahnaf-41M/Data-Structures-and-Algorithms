#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000];
int color[1000], parent[1000];
int n, m;
bool ok = true;
int cycle_start, cycle_end;

void dfs(int nd)
{
   color[nd] = 1;

   for (auto x : adj[nd]) {
      if (!color[x]) {
         parent[x] = nd;
         dfs(x);
      }
      else if (color[x] == 1) {
         cycle_end = nd;
         cycle_start = x;
         ok = false;
         return;
      }
   }
   if (!ok)
      return;
   color[nd] = 2;
}
int main()
{
   cin >> n >> m;
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

   for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
   }
   for (int i = 1; i <= n; i++)
      if (!color[i])
         dfs(i);
   if (ok)
      cout << "Graph is Acyclic!\n";
   else {
      vector<int> Cycle;
      Cycle.push_back(cycle_start);

      for (int v = cycle_end; v != cycle_start; v = parent[v])
         Cycle.push_back(v);
      Cycle.push_back(cycle_start);
      reverse(Cycle.begin(), Cycle.end());

      cout << "Cycle:\n";
      for (int x : Cycle) cout << x << " ";
      cout << '\n';
   }

}
