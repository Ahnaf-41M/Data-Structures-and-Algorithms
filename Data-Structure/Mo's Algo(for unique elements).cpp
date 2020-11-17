/*Distinct elements in a range [L..R]*/
#include <bits/stdc++.h>
#include <ext/rope>

#define  pb   push_back
#define  ll   long long
#define  endl "\n"
#define  MX   200005

#define  W(t)            while(t--)
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        (a*b)/gcd(a,b)
#define  rep(i,a,b)      for(ll i = a; i <= b; i++)

using namespace std;
using namespace __gnu_cxx;

struct Query
{
   int L, R, indx;
};
int a[30005], freq[1000005], ans[MX];
Query Q[MX];
int n, q, unq;
const int block = 700;

bool cmp(Query a, Query b)
{
   if (a.L / block != b.L / block)
      return a.L < b.L;
   return a.R < b.R;
}
void Add(int pos)
{
   freq[a[pos]]++;
   if (freq[a[pos]] == 1)
      unq++;
}
void Remove(int pos)
{
   freq[a[pos]]--;
   if (!freq[a[pos]])
      unq--;
}
void AnswerQuery()
{
   int cur_L = 0, cur_R = -1;

   rep(i, 0, q - 1)
   {
      int left = Q[i].L;
      int right = Q[i].R;

      while (cur_L > left)
         cur_L--, Add(cur_L);
      while (cur_R < right)
         cur_R++, Add(cur_R);

      while (cur_L < left)
         Remove(cur_L), cur_L++;
      while (cur_R > right)
         Remove(cur_R), cur_R--;

      ans[Q[i].indx] = unq;
   }
   rep(i, 0, q - 1) cout << ans[i] << endl;
}
int main()
{
   ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
   cin >> n;
   rep(i, 0, n - 1) cin >> a[i];

   cin >> q;
   rep(i, 0, q - 1) {
      cin >> Q[i].L >> Q[i].R;
      Q[i].indx = i; Q[i].L--, Q[i].R--;
   }

   sort(Q, Q + q, cmp);
   AnswerQuery();
   return 0;
}
