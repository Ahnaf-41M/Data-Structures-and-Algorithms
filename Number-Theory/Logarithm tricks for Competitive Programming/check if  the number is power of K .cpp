// C++ implementation to check if
// the number is power of K

#include <bits/stdc++.h>

using namespace std;

// Function to check if
// the number is power of K
bool isPower(int N, int K)
{
	// logarithm function to
	// calculate value
	int res1 = log(N) / log(K);
	double res2 = log(N) / log(K);

	// compare to the result1
	// or result2 both are equal
	return (res1 == res2);
}

// Driver Code
int main()
{
	int N = 8;
	int K = 2;

	if (isPower(N, K)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}
