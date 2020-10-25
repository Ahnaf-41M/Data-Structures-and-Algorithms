#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int mn_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[mn_idx]) {
				mn_idx = j;
			}
		}
		swap(a[i], a[mn_idx]);
	}
}
int main()
{
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	SelectionSort(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}