#include<bits/stdc++.h>
using namespace std;
#define mx 100005

int par[mx], m, n, q;

int find(int a)
{
    if (par[a] == a)
        return a;
    else
        return par[a] = find(par[a]);
}
void Union(int a, int b)
{
    int a1 = find(a);
    int b1 = find(b);
    if (a1 != b1)
        par[a1] = b1;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        par[i] = i;
    while (m--)
    {
        int u, v; cin >> u >> v;
        Union(u, v);
    }
    cin >> q;
    while (q--)
    {
        int x, y; cin >> x >> y;
        int p1 = find(x);
        int p2 = find(y);
        if (par[p1] == par[p2])
            cout << "They are in same set.\n";
        else
            cout << "They are not in the same set.\n";
    }

    return 0;
}