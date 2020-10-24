#include <bits/stdc++.h>
using namespace std;

// Finds the maximum substring with exactly k unique chars
void kUniques(string s, int k)
{
	int cnt = 0;
	int n = s.length();

	map<char, int> count, freq;

	for (int i = 0; i < n; i++)
		count[s[i]]++;

	//If there are not enough unique characters, show an error message.
	if (count.size() < k)
	{
		cout << "Not enough unique characters";
		return;
	}

	int curr_start = 0, curr_end = 0;
	int max_window_size = 0, max_window_start = 0;

   /*Maintain a window and add elements to the window till it contains
    less or equal k, update our result if required while doing so. 
    If unique elements exceeds than required in window, start removing 
    the elements from left side.*/
	for (int i = 0; i < n; i++)
	{
		freq[s[i]]++;
		if (freq[s[i]] == 1)
			cnt++;

		/* If there are more than k unique characters in current
		   window, remove from left side*/
		while (cnt > k)
		{
			freq[s[curr_start]]--;
			if (freq[s[curr_start]] == 0)
				cnt--;
			curr_start++;
		}

		// Update the max window size if required
		if (i - curr_start + 1 > max_window_size)
		{
			max_window_size = i - curr_start + 1;
			max_window_start = curr_start;
		}
	}

	cout << "Max subtring is : " << s.substr(max_window_start, max_window_size)
	     << " with length " << max_window_size << endl;
}
int main()
{
	string s = "aabacbebebe";
	int k = 3;
	kUniques(s, k);
	return 0;
}
