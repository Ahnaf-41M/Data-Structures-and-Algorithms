#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;

		/* Move elements of arr[0..i-1], that are greater than
		  key, to one position ahead of their current position. */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
int main()
{
	int n; cin >> n;
	int arr[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	InsertionSort(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}
