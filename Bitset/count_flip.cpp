#include <bits/stdc++.h>
using namespace std;

int main()
{
	bitset<8> bt("10110011");
	cout << "size: " << bt.size() << endl;
	cout << "ones: " << bt.count() << endl;
	cout << "zeroes: " << bt.size() - bt.count() << endl;
	cout << "flip(1): " << bt.flip(1) << endl; //10110001
	cout << "flip(): " << bt.flip() << endl; //01001110
}