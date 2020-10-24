#include <bits/stdc++.h>
using namespace std;

int binarySearch(int n, int left, int right, int a[], int val)
{
	while ( left <= right ) {
		int mid = (left + right) / 2;

		if ( a[mid] == val )
			return mid;
		if ( a[mid] > val )
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
int main()
{
	int a[] = {2, 3, 5, 6, 9, 13, 21};
	int n = sizeof(a) / sizeof(a[0]);
	int pos = binarySearch(n, 0, n - 1, a, 9);

	if (pos == -1)
		cout << "Value is not found!";
	else
		cout << "Value is found at position " << pos;
}