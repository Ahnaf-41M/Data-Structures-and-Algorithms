/*k'th element in the range from l to r(with point update).
  Build Complexity — O(n log^2 n)
  Query Complexity — O(log^3 n)
  Update Complexity — O(log^2 n) */
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>, //use less_equal for storing duplicates
   rb_tree_tag, tree_order_statistics_node_update>;

const int MX = 1e5;
int ar[MX], n, q;
ordered_set<pair<int, int> > segTree[4 * MX];

void build(int node, int b, int e)
{
   if (b == e) {
      segTree[node].insert({ar[b], b});
      return;
   }
   for (int i = b; i <= e; i++)
      segTree[node].insert({ar[i], i});

   int left = node << 1;
   int right = left + 1;
   int mid = (b + e) >> 1;
   build(left, b, mid);
   build(right, mid + 1, e);
}
int Query(int node, int b, int e, int l, int r, int val, int idx)
{
   if (b > r || e < l) return 0;
   if (b >= l && e <= r) {
      int res = segTree[node].order_of_key({val, idx});
      return res;
   }
   int left = node << 1;
   int right = left + 1;
   int mid = (b + e) >> 1;

   int p1 = Query(left, b, mid, l, r, val, idx);
   int p2 = Query(right, mid + 1, e, l, r, val, idx);
   return p1 + p2;
}
void Update(int node, int b, int e, int ind, int prv, int now)
{
   if (b > ind || e < ind) return;
   if (b == ind && e == ind) {
      segTree[node].erase(segTree[node].find({prv, ind})); //erase old value
      segTree[node].insert({now, ind}); //insert new value
      return;
   }
   int left = node << 1;
   int right = left + 1;
   int mid = (b + e) >> 1;
   segTree[node].erase(segTree[node].find({prv, ind})); //erase old value
   segTree[node].insert({now, ind}); //insert new value
}
signed main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   int mn = INT_MAX, mx = -1;
   cin >> n;
   for (int i = 1; i <= n; i++) {
      cin >> ar[i];
      mn = min(mn, ar[i]);
      mx = max(mx, ar[i]);
   }
   build(1, 1, n);

   cin >> q;
   while (q--) {
      int type;
      cin >> type;
      if (type == 0) { //k'th element in the range from l to r
         int l, r, k;
         cin >> l >> r >> k;
         int low = mn, high = mx, ans;

         while (low <= high) {
            //check if this mid value is >= k'th number 
            int mid = (low + high) >> 1;
            int cur_ind = Query(1, 1, n, l, r, mid, (int)(1e9));
            if (cur_ind >= k) {
               ans = mid;
               high = mid - 1;
            }
            else low = mid + 1;
         }
         cout << "Ans: " << ans << endl;
      }
      else {
         int ind, val;
         cin >> ind >> val;
         Update(1, 1, n, ind, ar[ind], val);
         ar[ind] = val;
      }
   }
}
