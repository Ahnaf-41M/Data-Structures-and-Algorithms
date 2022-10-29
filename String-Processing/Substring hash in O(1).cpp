#include <bits/stdc++.h>
#define MX     1000003
#define mod    1000003
#define int    long long
using namespace std;

int pref[MX], inv[mod];
string s;
int p = 53;

int Pow(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		p >>= 1;
	}
	return res;
}
void ModInverse()
{
	inv[0] = 1;
	inv[1] = Pow(p, mod - 2); //p^-1 % mod = Pow(p, mod-2)
	for (int i = 2; i < mod; i++)
		inv[i] = (inv[i - 1] * inv[1]) % mod; //a^-n = a^(-n+1) * a^(-1)
}
void Pre_Cal()
{
	int curP = 53;
	pref[0] = s[0] - 'a' + 1;
	for (int i = 1; i < (int)s.size(); i++) {
		pref[i] = (pref[i - 1] + (s[i] - 'a' + 1) * curP) % mod;
		curP = (curP * p) % mod;
	}
}
int Hash(int l, int r)
{
	int ans = pref[r];
	if (l) ans -= pref[l - 1];
	if (ans < 0) ans += mod;
	ans = (ans * inv[l]) % mod;
	return ans;
}
signed main()
{
	cin >> s;

	ModInverse();
	Pre_Cal();

	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r; l--, r--;
		cout << Hash(l, r) << "\n";
	}

}