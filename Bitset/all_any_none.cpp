#include <bits/stdc++.h>
using namespace std;

int main()
{
	bitset<8> bt;
	cin >> bt;

	cout << "all: "<<bt.all()<<endl;
	cout << "any: "<<bt.any()<<endl;
	cout << "none: "<<bt.none()<<endl;
}