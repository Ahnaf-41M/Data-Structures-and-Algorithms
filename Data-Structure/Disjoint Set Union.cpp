#include<bits/stdc++.h>
using namespace std;
#define mx 100005

int par[mx], m, n, q, Rank[mx];

int root(int a)
{
    if (par[a] == -1)
        return a;
    else
        return par[a] = root(par[a]);
}
void Union(int a, int b)
{
    int p1 = root(a);
    int p2 = root(b);

    if (p1 == p2) return;

    if (Rank[p1] > Rank[p2]) {
        par[p2] = p1;
        Rank[p1] += Rank[p2];
    }
    else{
        par[p1] = p2;
        Rank[p2] += Rank[p1];
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        par[i] = -1, Rank[i] = 1;

    while (m--) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    cin >> q;
    while (q--)
    {
        int x, y; cin >> x >> y;
        int p1 = root(x);
        int p2 = root(y);
        if (p1 == p2)
            cout << "They are in same set.\n";
        else
            cout << "They are not in the same set.\n";
    }

    return 0;
}
