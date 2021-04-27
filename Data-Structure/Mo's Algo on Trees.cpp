/*If there is a vertex in the path from x to y assigned value c.*/
#include <bits/stdc++.h>
#define  pb push_back
#define  mx 100005
using namespace std;

vector<int> adj[mx], euler;
int LCA[mx][22];
int par[mx], lev[mx], ans[2 * mx], numC[mx], freq_node[mx];
int n, m, q, sz, in_Time[mx], out_Time[mx], freq_val[mx];
bool vis[mx];
int timer = 1;
const int block = 700;

struct Query
{
   int L, R, indx, C, lca;
};
Query Q[2 * mx];

void dfs(int nd, int pr)
{
   euler.pb(nd);
   in_Time[nd] = timer++;
   LCA[nd][0] = pr;

   for (int ch : adj[nd])
      if (ch != pr) {
         par[ch] = nd;
         lev[ch] = lev[nd] + 1;
         dfs(ch, nd);
      }
   euler.pb(nd);
   out_Time[nd] = timer++;
}
void buildLCA()
{
   for (int j = 1; j <= sz; j++) {
      for (int i = 1; i <= n; ++i) {
         if (LCA[i][j - 1] != -1) {
            int pp = LCA[i][j - 1];
            LCA[i][j] = LCA[pp][j - 1];
         }
      }
   }
}
int findLCA(int a, int b)
{
   if (lev[a] > lev[b])
      swap(a, b);
   int d = lev[b] - lev[a];

   while (d > 0)
   {
      int i = log2(d);
      b = LCA[b][i];
      d -= (1 << i);
   }
   if (a == b) return a;

   for (int i = sz; i >= 0; i--)
      if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
         a = LCA[a][i], b = LCA[b][i];
   return par[a];
}
void init()
{
   sz = log2(n);

   for (int i = 0; i <= n; i++)
      for (int j = 0; j <= sz; j++)
         LCA[i][j] = -1;

   for (int i = 1; i <= n; i++)
      cin >> numC[i];
   for (int i = 0; i < n - 1; i++)
   {
      int x, y; cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
}
bool cmp(Query a, Query b)
{
   if (a.L / block != b.L / block)
      return a.L < b.L;
   return a.R < b.R;
}
void Add(int pos)
{
   int node = euler[pos];
   int val = numC[node];
   freq_node[node]++;

   if (freq_node[node] == 1)
      freq_val[val]++;
   else
      freq_val[val]--;
}
void Remove(int pos)
{
   int node = euler[pos];
   int val = numC[node];
   freq_node[node]--;

   if (freq_node[node] == 1)
      freq_val[val]++;
   else
      freq_val[val]--;
}
void AnswerQueries()
{
   int cur_L = 1, cur_R = 0;

   for (int i = 1; i <= m; i++) {
      int left = Q[i].L;
      int right = Q[i].R;
      int LCA = Q[i].lca;

      while (cur_L > left) cur_L--, Add(cur_L);
      while (cur_R < right) cur_R++, Add(cur_R);

      while (cur_L < left) Remove(cur_L), cur_L++;
      while (cur_R > right) Remove(cur_R), cur_R--;

      ans[Q[i].indx] = (freq_val[Q[i].C] ? 1 : 0);
      if ((LCA != -1 && numC[LCA] == Q[i].C))
         ans[Q[i].indx] = 1;
   }
   for (int i = 1; i <= m; i++)
      cout << (ans[i] ? "Find\n" : "NotFind\n");
}

int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

   /*First, flatten the tree into an array(euler). Store in time and out time
   of nodes.
   Case 1: if LCA(x,y) = x, then l = in_Time[x] and r = in_Time[y]. 
   Case 2: if LCA(x,y) != x, then l = out_Time[x], r = in_Time[y].
   For both the cases, nodes that occurs zero/twice in the range
   from l to r won't be counted. */
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t = 0;

   cin >> n >> m;

   euler.pb(0);
   init();
   dfs(1, -1);
   buildLCA();

   for (int i = 1; i <= m; i++)
   {
      int x, y, c; cin >> x >> y >> c;
      if (in_Time[x] > in_Time[y]) swap(x, y);
      Q[i].indx = i; Q[i].C = c;
      Q[i].lca = findLCA(x, y);
      // cout << "LCA(" << x << "," << y << "): " << findLCA(x, y) << endl;
      if (Q[i].lca == x) {
         Q[i].lca = -1;
         Q[i].L = in_Time[x];
         Q[i].R = in_Time[y];
      }
      else {
         Q[i].L = out_Time[x];
         Q[i].R = in_Time[y];
      }
   }
   sort(Q + 1, Q + 1 + m, cmp);
   AnswerQueries();

   cout << "\n";

}
