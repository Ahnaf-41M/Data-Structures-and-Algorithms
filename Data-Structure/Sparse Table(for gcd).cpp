#include<bits/stdc++.h>
using namespace std;

int n, sq, query;
int a[10000];
vector<vector<int> > table;

void BuildTable()
{
	//Initialize table for the interval length 1.(2^0)
	for (int i = 0; i < n; i++)
		table[i][0] = a[i];
	for (int j = 1; j <= sq; j++)
	{
		// Compute minimum value for all intervals with size 2^j
		for (int i = 0; (i + (1 << j) - 1) < n; i++)
		{
			//suppose for j=2,we will check (i,2^j-1) and (i+2^j-1,j-1) value
			//meaning for j=2,i=0, table[0][3] & table[3][3]
			table[i][j] = __gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	sq = log2(n);
	table.assign(n + 1, vector<int>(sq + 1));

	BuildTable();
	cin >> query;

	while (query--)
	{
		/*Compute GCD of last 2^j elements with first 2^j elements in range. 
      For [2, 10], we find GCD of arr[lookup[0][3]] and arr[lookup[3][3]].*/

		int left, right; cin >> left >> right;
		
		int j = log2(right - left + 1);
		cout << __gcd(table[left][j], table[right - (1 << j) + 1][j]) << endl;
	}
}
