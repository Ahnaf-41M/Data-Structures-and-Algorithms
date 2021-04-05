#include<bits/stdc++.h>
using namespace std;
#define  mx   100005
#define  int  long long

struct edge
{
   int x, y, w;
};

edge adj[mx];
int n, m, sum;
int parent[mx], Rank[mx];

bool cmp(edge p1, edge p2)
{
   return p1.w < p2.w;
}
int root(int d)
{
   if (parent[d] < 0) return d;
   else
      return parent[d] = root(parent[d]);
}
void Union(int a, int b, int wt)
{
   if (a == b)
      return;
   if (Rank[a] > Rank[b]) {
      parent[b] = a;
      Rank[a] += Rank[b];
   }
   else {
      parent[a] = b;
      Rank[b] += Rank[a];
   }
   sum += wt;
}
signed main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

   int a, b;
   cin >> n >> m;

   for (int i = 1; i <= n; i++)
      parent[i] = -1, Rank[i] = 1;
   for (int i = 0; i < m; i++)
      cin >> adj[i].x >> adj[i].y >> adj[i].w;

   sort(adj, adj + m, cmp);

   for (int i = 0; i < m; i++) {
      a = root(adj[i].x);
      b = root(adj[i].y);
      Union(a, b, adj[i].w);
   }
   cout << sum << endl;
}
