/*Smaller or equal elements than x in range l to r.*/
#include <bits/stdc++.h>
using namespace std;
#define MX     100005
#define pb     push_back
#define all(v) v.begin(),v.end()

vector<int> segTree[4000];
int a[MX], n, m;

void build(int node, int b, int e)
{
   if (b == e) {
      segTree[node].pb(a[b]);
      return;
   }
   int mid = (b + e) / 2;
   int left = node << 1;
   int right = (node << 1) + 1;

   build(left, b, mid);
   build(right, mid + 1, e);

   int i = 0, j = 0;

   merge(all(segTree[left]),all(segTree[right]),back_inserter(segTree[node]));
   // while (i < segTree[left].size() && j < segTree[right].size())
   // {
   //    if (segTree[left][i] <= segTree[right][j])
   //       segTree[node].pb(segTree[left][i]), i++;
   //    else
   //       segTree[node].pb(segTree[right][j]), j++;
   // }
   // while (i < segTree[left].size())
   //    segTree[node].pb(segTree[left][i]), i++;
   // while (j < segTree[right].size())
   //    segTree[node].pb(segTree[right][j]), j++;
}
int Query(int node, int b, int e, int l, int r, int x)
{
   if (b > r || e < l)
      return 0;
   if (b >= l && e <= r)
      return upper_bound(all(segTree[node]), x) - segTree[node].begin();

   int mid = (b + e) / 2;
   int left = (node << 1);
   int right = (node << 1) + 1;

   int r1 = Query(left, b, mid, l, r, x);
   int r2 = Query(right, mid + 1, e, l, r, x);

   return r1 + r2;
}
int main()
{
   cin >> n;
   for (int i = 1; i <= n; i++)
      cin >> a[i];
   build(1, 1, n);

   cin >> m;

   while ( m-- )
   {
      int l, r, x; cin >> l >> r >> x;
      cout << Query(1, 1, n, l, r, x) << endl;
   }
}