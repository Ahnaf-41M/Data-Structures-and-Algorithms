#include <bits/stdc++.h>
using namespace std;
vector<int> ar[100001];
int vis[100001] , subSize[100001];

int dfs(int node, int par)
{
   vis[node] = 1;
   subSize[node] = 1;

   for (int child : ar[node])
      if (!vis[child]) {
         dfs(child, node);
         subSize[node] += subSize[child];
      }
}
int main() {
   int n , a , b;

   cin >> n;
   for (int i = 1; i < n; i++)   //for tree edges = n-1
      cin >> a >> b , ar[a].push_back(b) , ar[b].push_back(a);

   //call dfs(1) when 1 is root , if another node is root than pass that node
   dfs(1, -1);

   for (int i = 1; i <= n; i++)
      cout << "sub tree size of node " << i << " is " << subSize[i] << endl;
}
