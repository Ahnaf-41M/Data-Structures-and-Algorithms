#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int left, int mid, int right)
{
   int n1 = mid - left + 1;
   int n2 = right - mid;

   int L[n1], R[n2];

   for (int i = 0; i < n1; i++)
      L[i] = a[left + i];
   for (int i = 0; i < n2; i++)
      R[i] = a[mid + i + 1];

   int i = 0, j = 0, k = left;

   while ( i < n1 && j < n2)
   {
      if (L[i] <= R[j])
         a[k++] = L[i++];
      else
         a[k++] = R[j++];
   }
   /*Copy the remaining elements of L[] and R[] if there are any. */
   while ( i < n1 )
      a[k++] = L[i++];
   while ( j < n2 )
      a[k++] = R[j++];
}
void mergeSort(int a[], int left, int right)
{
   if (left < right) {
      int mid = (left + right) / 2;
      
      /*Sort the 2 halves.*/
      mergeSort(a, left, mid);
      mergeSort(a, mid + 1, right);
      /*Finally merge them.*/
      merge(a, left, mid, right);
   }
}
int main()
{
   int n; cin >> n;
   int arr[n];
   for(int i = 0; i < n; i++)
      cin >> arr[i];

   mergeSort(arr, 0, n - 1);

   cout << "Sorted array is \n";
   for(int i = 0; i < n; i++)
      cout << arr[i] << " ";
   return 0;
}