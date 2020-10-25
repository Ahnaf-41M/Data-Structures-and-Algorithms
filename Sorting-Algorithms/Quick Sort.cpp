#include <bits/stdc++.h>
using namespace std;

int Partition(int a[], int l, int h)
{
	int i = l, j = h;
	int pivot = a[l]; //picking the first element as pivot

	do {

		do { i++; } while ( a[i] <= pivot ); //if the i'th element is less than or equal
		do { j--; } while ( a[j] > pivot ); //if the j'th element is greater

		if (i < j)
			swap(a[i], a[j]);
	} while ( i < j );
	
	swap(a[l], a[j]);
	return j;
}
void QuickSort(int a[], int l, int h)
{
	if (l < h) {
		int part_ind = Partition(a, l, h);

		QuickSort(a, l, part_ind);
		QuickSort(a, part_ind + 1, h);
	}
}
int main()
{
	int n; cin >> n;
	int a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];
	QuickSort(a, 0, n - 1);

	cout << "After Sorting:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}