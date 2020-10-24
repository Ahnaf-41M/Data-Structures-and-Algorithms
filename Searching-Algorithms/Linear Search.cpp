#include <bits/stdc++.h>
using namespace std;

int linearSearch(int n, int a[], int val)
{
	int pos = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == val) {
			pos = i;
			break;
		}
	}
	return pos;
}
int main()
{
	int a[] = {2, 3, 5, 6, 9, 13, 21};
	int n = sizeof(a) / sizeof(a[0]);
	int pos = linearSearch(n, a, 9);

	if (pos == -1)
		cout << "Value is not found!";
	else
		cout << "Value is found at position " << pos;
}