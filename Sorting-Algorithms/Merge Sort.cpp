#include<bits/stdc++.h>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for(int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for(int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	int i = 0, j = 0; 
	int k = l;// Initial index of merged subarray
	
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j]) 
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[] and R[] if there are any 
	while (i < n1) 
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void MergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
int main()
{
	int n; cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	MergeSort(arr, 0, n - 1);

	cout << "Sorted array is:\n";
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
