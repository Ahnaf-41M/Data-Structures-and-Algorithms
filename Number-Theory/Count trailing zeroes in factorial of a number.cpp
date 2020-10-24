#include <bits/stdc++.h>
using namespace std;

int main()
{
	/*Trailing 0s in n! = Count of 5s in prime factors of
	 n! = floor(n/5) + floor(n/25) + floor(n/125) + ....*/
	int t, n, cnt = 0;
	cin >> n;
	for (int i = 5; n / i >= 1; i *= 5)
		cnt += (n / i);
	cout << cnt << endl;
}