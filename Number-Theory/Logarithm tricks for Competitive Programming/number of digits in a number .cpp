#include <bits/stdc++.h>
using namespace std;
int countDigit(long long n)
{
	return floor(log10(n) + 1);
}
int main()
{
	double N = 80;

	cout << countDigit(N);
	return 0;
}
