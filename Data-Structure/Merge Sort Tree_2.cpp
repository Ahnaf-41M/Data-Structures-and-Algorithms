/*k'th element in the range l to r.*/
#include <bits/stdc++.h>
#define  MX         100005
#define  ff         first
#define  ss         second
#define  ll         long long int
#define  all(v)     v.begin(), v.end()
#define  rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;

vector<int> tree[4 * MX];
pair<int, int> v[MX];
int n, m, q;
int a[MX];
void build(int node, int b, int e)
{
   if (b == e) {
      tree[node].push_back(v[b].ss);
      return;
   }
   int mid = (b + e) / 2;
   int left = node << 1;
   int right = (node << 1) + 1;

   build(left, b, mid);
   build(right, mid + 1, e);

   merge(all(tree[left]), all(tree[right]), back_inserter(tree[node]));
}
int Query(int node, int b, int e, int l, int r, int k)
{
   if (b == e) return tree[node][0];

   int mid = (b + e) / 2;
   int left = node << 1;
   int right = (node << 1) + 1;

   int l_in_query_range = lower_bound(all(tree[left]), l) - tree[left].begin();
   int r_in_query_range = upper_bound(all(tree[left]), r) - tree[left].begin();

   int diff = r_in_query_range - l_in_query_range;

   if (diff >= k)
      return Query(left, b, mid, l, r, k);
   else
      return Query(right, mid + 1, e, l, r, k - diff);
}
int main()
{
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   cin >> n >> m;

   rep(i, 1, n) {
      cin >> a[i];
      v[i].ff = a[i];
      v[i].ss = i;
   }
   sort(v + 1, v + 1 + n);

   build(1, 1, n);

   while (m--)
   {
      int l, r, k; cin >> l >> r >> k;
      int indx = Query(1, 1, n, l, r, k);
      cout << a[indx] << endl;

   }
}