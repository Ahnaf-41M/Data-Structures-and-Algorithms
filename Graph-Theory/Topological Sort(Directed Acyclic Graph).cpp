#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10003];
bool vis[10000];
vector<int> ts;

void DFS(int nd)
{
   vis[nd] = true;

   for (int it : adj[nd])
      if (!vis[it])
         DFS(it);
   ts.push_back(nd);
}
int main()
{
   int n, e;
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);

   cin >> n >> e;

   for (int i = 0; i < e; i++){
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
   }

   for (int i = 0; i < n; i++) 
      if (!vis[i])
         DFS(i);
   
   for (int i = ts.size() - 1; i >= 0; i--)
      cout << ts[i] << " ";

}
