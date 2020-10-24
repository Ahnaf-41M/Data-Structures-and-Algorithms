#include <bits/stdc++.h>
using namespace std;

string str, pat, ans;
int start_index;

int findSubstr()
{
	int freq_str[256] = {};
	int freq_pat[256] = {};

	for (int i = 0; i < pat.size(); i++)
		freq_pat[pat[i]]++;

	int len = pat.size();
	int mn_len = str.size(), left = 0, cnt = 0;
	start_index = -1;

	for (int i = 0; i < str.size(); i++) {
		freq_str[str[i]]++;

		if (freq_pat[str[i]] && freq_str[str[i]] <= freq_pat[str[i]])
			cnt++;
		if (cnt == len) {
   /*If the character at left position is not present in pattern string or  
     the frequency of the character is greater in string then increment left.*/
			while (!freq_pat[str[left]] ||
			       freq_str[str[left]] > freq_pat[str[left]]) {
				freq_str[str[left]]--;
				left++;
			}
			int cur_l = i - left + 1;
			if (mn_len > cur_l) {
				mn_len = cur_l;
				start_index = left;
			}
		}
	}
	ans = str.substr(start_index, mn_len);

	return mn_len;
}
int main()
{
	cin >> str;
	cin >> pat;
	cout << "Smallest window size is: " << findSubstr() << endl;
	cout << "The window is: " << ans << endl;
}