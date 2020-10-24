#include <bits/stdc++.h>
using namespace std;
#define mx 100005
#define pii pair<int,int>
#define INF 1000000000
vector<pii> adj[mx];
int n, m;

int BFS(int st)
{
   vector<int> dis(n + 1, INF);
   dis[st] = 0;
   deque<int> dq;

   dq.push_front(st);

   while (!dq.empty())
   {
      int nd = dq.front();
      dq.pop_front();

      for (auto ch : adj[nd])
      {
         int cur = ch.first;
         int wt = ch.second;

         if (dis[nd] + wt < dis[cur])
         {
            dis[cur] = dis[nd] + wt;

            if (wt == 0)
               dq.push_front(cur);
            else
               dq.push_back(cur);
         }
      }
   }
   return (dis[n] == INF ? -1 : dis[n]);
}
int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   cin >> n >> m;

   while (m--)
   {
      int x, y, w;
      cin >> x >> y >> w;
      adj[x].push_back({y, w});
      adj[y].push_back({x, w});
   }
   cout << "Distance from 1 to " << n << " is: " << BFS(1) << endl;
}
