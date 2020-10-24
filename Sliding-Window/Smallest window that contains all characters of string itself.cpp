#include<bits/stdc++.h>
using namespace std;

string s, ans;
int start_index;

int findSubstring(string s)
{
	int n = s.size();
	set<char> st;

	for (int i = 0; i < n; i++)
		st.insert(s[i]);
	int distinct = st.size();
	start_index = -1;

	int left = 0, mn_len = n, cnt = 0;
	int freq[256] = {};

	for (int i = 0; i < n; i++) {
		freq[s[i]]++;

		if (freq[s[i]] == 1)
			cnt++;
		if (cnt == distinct) {
			while (freq[s[left]] > 1) {
				freq[s[left]]--;
				left++;
			}
			int cur_l = i-left+1;
			if(mn_len > cur_l){
				mn_len = cur_l;
				start_index = left;
			}
		}
	}
	ans = s.substr(left, mn_len);
	return mn_len;
}
int main()
{
	cin >> s;
	cout << "Smallest window containing all distinct"
	     << " characters is: " << findSubstring(s) << endl;;
	cout << "The sub-string is: " << ans << endl;
}