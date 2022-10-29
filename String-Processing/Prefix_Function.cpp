#include <bits/stdc++.h>
using namespace std;

vector<int> Pref_Func(string s)
{
    int n = s.size();
    vector<int> v(n);

    for (int i = 1; i < n; i++) {
        int j = v[i - 1];
        while (j > 0 && s[i] != s[j])
            j = v[j - 1];
        if (s[i] == s[j]) j++;
        v[i] = j;
    }
    return v;
}
signed main()
{
    string s;
    vector<int> lps;

    cin >> s;
    lps = Pref_Func(s);
    for (int x : lps) cout << x << " ";
}