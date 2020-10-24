#include<bits/stdc++.h>
using namespace std;
#define N 201
int A[N][N], Identity[N][N];

void multiply(int I[][N], int ar[][N], int dim)
{
	//normal matrix multiplication
	int res[dim + 1][dim + 1] = {};
	for (int i = 1; i <= dim; i++)
		for (int j = 1; j <= dim; j++)
			for (int k = 1; k <= dim; k++)
				res[i][j] += I[i][k] * ar[k][j];

	for (int i = 1; i <= dim; i++)
		for (int j = 1; j <= dim; j++)
			I[i][j] = res[i][j];
}
void Power(int ar[][N], int dim, int n)
{
	for (int i = 1; i <= dim; i++) {
		for (int j = 1; j <= dim; j++) {
			if (i == j)
				Identity[i][j] = 1;
			else
				Identity[i][j] = 0;
		}
	}

	//Using Binary Exponetiation for calculating (A[][])^n
	while (n)
	{
		if (n & 1)
			multiply(Identity, ar, dim), n--;
		else
			multiply(ar, ar, dim), n /= 2;
	}

	for (int i = 1; i <= dim; i++)
		for (int j = 1; j <= dim; j++)
			ar[i][j] = Identity[i][j];
}

int main()
{
	//for calculation (A[][])^n
	int n, dim;

	cin >> dim >> n;

	for (int i = 1; i <= dim; i++)
		for (int j = 1; j <= dim; j++)
			cin >> A[i][j];

	Power(A, dim, n);

	for (int i = 1; i <= dim; i++) {
		for (int j = 1; j <= dim; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

}