#include <bits/stdc++.h>
using namespace std;

int main()
{
	bitset<4> bt("1001");
	cout << "set(2): " << bt.set(2) << endl; //1101
	cout << "set: " << bt.set() << endl; //1111
	cout << "set(2,0): " << bt.set(2, 0) << endl; //1011

	cout << "reset(1): " << bt.reset(1) << endl; //1001
	cout << "reset: " << bt.reset() << endl; //0000

	bt[0] = 1; //0001

	for (int i = 0; i < bt.size(); i++)
		cout << bt.test(i) << endl;
}