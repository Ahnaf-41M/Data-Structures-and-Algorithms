#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k, i = 0;

	cin >> n >> k;

	int a[n];
	deque<int> Q;

	for (i = 0; i < n; i++)
		cin >> a[i];

	for (i = 0; i < k; i++) {
		while (!Q.empty() && a[i] > a[Q.back()]) {
			Q.pop_back();
		}
		Q.push_back(i);
	}

	for (; i < n; i++) {
		cout << a[Q.front()] << " ";
		//remove the elements which are not in the part of the window
		while (!Q.empty() && Q.front() <= (i - k))
			Q.pop_front();
		//remove the elements which are not useful but in the window
		while (!Q.empty() && a[i] >= a[Q.back()])
			Q.pop_back();
		Q.push_back(i);
	}
	cout<<a[Q.front()]<<endl;
}