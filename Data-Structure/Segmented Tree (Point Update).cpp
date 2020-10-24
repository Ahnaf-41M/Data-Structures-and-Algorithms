#include<bits/stdc++.h>
using namespace std;

#define Max 100001
int a[Max];
int tree[Max * 3];

void init(int node, int b, int e)
{
   if (b == e)
   {
      tree[node] = a[b];
      return;
   }
   int left = 2 * node;
   int right = 2 * node + 1;
   int mid = (b + e) / 2;

   init(left, b, mid);
   init(right, mid + 1, e);
   tree[node] = tree[left] + tree[right];
}
int query(int node, int b, int e, int i, int j)
{
   if (i > e || j < b)
      return 0;
   if (b >= i && e <= j)
      return tree[node];
   int Left = node * 2;
   int Right = node * 2 + 1;
   int mid = (b + e) / 2;

   int p1 = query(Left, b, mid, i, j);
   int p2 = query(Right, mid + 1, e, i, j);

   return p1 + p2;
}
void update(int node, int b, int e, int ind, int nv)
{
   if (ind > e || ind < b)
   {
      return;
   }
   if (b >= ind && e <= ind)
   {
      tree[node] = nv;
      return ;
   }
   int left = 2 * node;
   int right = 2 * node + 1;
   int mid = (b + e) / 2;

   update(left, b, mid, ind, nv);
   update(right, mid + 1, e, ind, nv);
   tree[node] = tree[left] + tree[right];
}
int main()
{
   int n, i;

   cout << "Enter n: ";
   cin >> n;
   cout << "Enter " << n << " values: ";
   for (i = 1; i <= n; i++)
   {
      cin >> a[i];
   }
   init (1, 1, n);
   int ind, nv;

   cout << "Enter a index and a new value : ";
   cin >> ind >> nv;
   update(1, 1, n, ind, nv);
   int p, q;
   cout << "Enter range(p&q): ";
   cin >> p >> q;
   cout << query(1, 1, n, p, q) << endl;
}

