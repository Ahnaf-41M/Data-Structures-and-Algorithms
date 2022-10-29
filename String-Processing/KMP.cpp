#include <bits/stdc++.h>
using namespace std;

vector<int> Pref_Func(string s)
{
	int len = s.size();
	vector<int> v(len);

	for (int i = 1; i < len; i++) {
		int j = v[i - 1];
		while (j > 0 && s[i] != s[j])
			j = v[j - 1];
		if (s[i] == s[j]) j++;
		v[i] = j;
	}
	return v;
}
void KMP(string txt, string pat)
{
	vector<int> lps = Pref_Func(pat);
	int n = txt.size(), m = pat.size();
	int i = 0, j = 0, found = 0;

	while (i < n) {
		while (j > 0 && txt[i] != pat[j])
			j = lps[j - 1];
		if (txt[i] == pat[j]) j++;
		if (j == m) {
			cout << i - j + 1 << " ";
			j = lps[j - 1];
			found = 1;
		}
		i++;
	}
	if (!found) cout << "Pattern not found!\n";
}
int main()
{
	string txt, pat;
	cin >> txt >> pat;
	KMP(txt, pat);
}