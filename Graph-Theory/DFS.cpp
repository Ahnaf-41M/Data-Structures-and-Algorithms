#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
bool vis[10005];
int n, m;

void dfs(int nd)
{
   cout << nd << " ";
   vis[nd] = true;

   for (int ch : adj[nd])
      if (!vis[ch])
         dfs(ch);
}
int main()
{
   cin >> n >> m;
   while (m--)
   {
      int x, y; cin >> x >> y;
      adj[x].push_back(y); adj[y].push_back(x);
   }
   cout << "The order of the dfs tree:\n";
   for (int i = 1; i <= n; i++)
      if (!vis[i])
         dfs(i);
}