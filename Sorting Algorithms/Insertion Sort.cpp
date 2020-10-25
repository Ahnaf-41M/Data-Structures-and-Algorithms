#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int a[], int n)
{
   for (int i = 1; i < n; i++) {
      int key = a[i];
      int j = i - 1;

    /*Move elements of arr[0..i-1], that are greater than
      key, to one position ahead of their current position */
      
      while ( j >= 0 && a[j] > key ) {
         a[j + 1] = a[j];
         j--;
      }
      a[j + 1] = key;
   }
}
int main()
{
   int n; cin >> n;
   int a[n];

   for (int i = 0; i < n; i++)
      cin >> a[i];
   InsertionSort(a, n);

   cout << "After Sorting:\n";
   for (int i = 0; i < n; i++)
      cout << a[i] << " ";
}