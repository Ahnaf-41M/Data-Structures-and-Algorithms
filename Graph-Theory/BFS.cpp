#include <bits/stdc++.h>
using namespace std;

int t;
int n, m;
int cost[11000];
vector<int>v[100005];

void bfs(int parent[])
{
   queue<int>q;
   q.push(1);
   cost[1] = 0;
   parent[1] = -1;
   while (!q.empty())
   {
      int idx = q.front();

      q.pop();
      for (int i = 0; i < v[idx].size(); i++)
      {
         int y = v[idx][i];
         if (cost[y] == -1)
         {
            q.push(y);
            cost[y] = cost[idx] + 1;
            parent[y] = idx;
         }
      }
   }
}

int main()
{
   cin >> t;
   while (t--)
   {
      memset(cost, -1, sizeof cost);

      scanf("%d%d", &n, &m);
      int parent[n + 1] = {0};

      for (int i = 0; i < m; i++)
      {
         int x, y;
         scanf("%d%d", &x, &y);
         v[x].push_back(y);
         v[y].push_back(x);
      }
      bfs(parent);
   }

}

