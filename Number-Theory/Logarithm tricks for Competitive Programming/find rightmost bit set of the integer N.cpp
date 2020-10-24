#include <bits/stdc++.h>

using namespace std;

// Function to find the rightmost
// bit set of the integer N
unsigned int getFirstSetBitPos(int n)
{
	return log2(n & -n) + 1;
}
int main()
{
	int N = 8;

	cout << getFirstSetBitPos(N);
	return 0;
}
