#include <bits/stdc++.h>
#define int    long long
#define pb     push_back
#define all(v) v.begin(),v.end()
using namespace std;

int mx = 1e5;
int mod = 1e6 + 3;
int Hash(string s)
{
	int curP = 1, p = 53, ans = 0;
	for (char ch : s) {
		ans = (ans + (ch - 'a' + 1) * curP) % mod;
		curP = (curP * p) % mod;
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	// cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		string s;
		cin >> s;
		cout << Hash(s) << "\n";
	}
}