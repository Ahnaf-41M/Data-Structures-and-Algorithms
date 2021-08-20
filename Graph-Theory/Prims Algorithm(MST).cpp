#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<ll,ll>

const int MAX = 1e5;
bool visited[MAX];
vector<PII> graph[MAX];

ll prims(ll x)
{
   priority_queue<PII, vector<PII>, greater<PII> > Q;
   ll minCost = 0;

   Q.push({0, x});

   while (!Q.empty())
   {
      auto cur = Q.top();
      Q.pop();

      x = cur.second;

      if (visited[x]) continue;

      visited[x] = true;
      minCost += cur.first;

      for (auto ch : graph[x])
         if (!visited[ch.second])
            Q.push(ch);
   }
   return minCost;
}
int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   ll nodes, edges, x, y, weight, minc = INT_MAX, stnode;

   cin >> nodes >> edges;

   for (int i = 0; i < edges; i++)
   {
      cin >> x >> y >> weight;
      graph[x].push_back({weight, y});
      graph[y].push_back({weight, x});
      if (minc > weight) {
         minc = weight;
         stnode = x;
      }
   }
   minc = prims(stnode);
   cout << minc << endl;
}
