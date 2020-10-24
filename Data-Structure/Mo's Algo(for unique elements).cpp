/*Distinct elements in a range [L..R]*/
#include<bits/stdc++.h>

#define ll  long long
#define rep(i,n)        for(int i = 0; i < n; i++)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define mx 600000

int ans[mx];
vector<int> a;
vector<pair<int, int> > Query;
map<pair<int, int>, int > ind;
const int block = 707;
int n, q;

int AnswerQueries()
{
     map<int, int> freq;
     int curR = 0, curL = 0, curUnq = 0;
     for (int i = 0; i < Query.size(); i++)
     {
          int L = Query[i].ff;
          int R = Query[i].ss;

          while (curL < L)
          {
               freq[a[curL]]--;
               if (!freq[a[curL]])
                    curUnq--;
               curL++;
          }
          while (curL > L)
          {
               freq[a[curL - 1]]++;
               if (freq[a[curL - 1]] == 1)
                    curUnq++;
               curL--;
          }
          while (curR <= R)
          {
               freq[a[curR]]++;
               if (freq[a[curR]] == 1)
                    curUnq++;
               curR++;
          }
          while (curR > R + 1)
          {
               freq[a[curR - 1]]--;
               if (!freq[a[curR - 1]])
                    curUnq--;
               curR--;
          }
          ans[ind[ {L, R}]] = curUnq;

     }
     for (int i = 0; i < q; i++)
          cout << ans[i] << endl;
}
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
     if (p1.ff / block != p2.ff / block)
          return p1.ff / block < p2.ff / block;
     else
          p1.ss < p2.ss;
}
int main()
{
     IOS
     int i;
     cin >> n >> q;

     rep(i, n) {
          int x; cin >> x;
          a.pb(x);
     }
     int k = 0;
     rep(i, q)
     {
          int l, r; cin >> l >> r;
          l--, r--;
          Query.pb({l, r});
          ind[ {l, r}] = k++;
     }
     sort(Query.begin(), Query.end(), cmp);
     AnswerQueries();

     return 0;
}

