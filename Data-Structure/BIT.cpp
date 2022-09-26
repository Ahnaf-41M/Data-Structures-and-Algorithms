#include<bits/stdc++.h>
#define MX  100005
#define int long long
using namespace std;

int ar[MX];
int n, q;
template <typename T>
struct BIT
{
    T n;
    vector<T> tree;

    void init(T N) {
        n = N;
        tree = vector<T> (n + 1);
    }
    void update(T pos, T val) {
        while (pos <= n) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
    T query(T pos) {
        T sum = 0;
        while (pos > 0) {
            sum += tree[pos];
            pos -= (pos & -pos);
        }
        return sum;
    }
    T query(T l, T r) {
        return query(r) - query(l - 1);
    }
    void clear_() { tree.clear(); }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    BIT<int> tree1;
    tree1.init(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        tree1.update(i, ar[i]);
    }

    cin >> q;
    while (q--) {
        int l, r; //sum of elements from 1 to m
        cin >> l >> r;
        cout << tree1.query(l, r) << "\n";
    }
}