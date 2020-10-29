#include <bits/stdc++.h>
using namespace std;

#define inf 10000000
int n, m;
void floydWarshall(vector<vector<int>> w, int n)
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			(w[i][j] == inf ? cout << "inf\t" : cout << w[i][j] << "\t");
		}
		cout << "\n";
	}
}
int main()
{
	cin >> n >> m;

	vector<vector<int> > w(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				w[i][j] = inf;
			}
		}
	}
	while (m--)
	{
		int x, y, wt; cin >> x >> y >> wt;
		w[x][y] = min(wt, w[x][y]);
	}
	floydWarshall(w, n);

}