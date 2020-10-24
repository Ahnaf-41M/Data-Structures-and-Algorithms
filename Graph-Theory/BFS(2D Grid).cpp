#include<bits/stdc++.h>

#define pb        push_back
#define endl      "\n"
#define ll        long long
#define W(t)      while(t--)
#define rep(i,n)  for(i = 0; i < n; i++)
using namespace std;

bool vis[50][50];
int dis[50][50];
int dx[] = { -2, -1, -2, -1, 1, 2, 2, 1};
int dy[] = { -1, -2, 1, 2, -2, -1, 1, 2};

int x2, y2;

bool is_valid(int a, int b)
{
	if (a > 8 || a < 1 || b > 8 || b < 1)
		return false;
	if (vis[a][b])
		return false;
	return true;
}
void bfs(int x1, int y1)
{
	vis[x1][y1] = true;
	queue<pair<int, int> > Q;
	Q.push({x1, y1});
	bool found = false;

	while (!Q.empty())
	{
		int x3 = Q.front().first;
		int y3 = Q.front().second;
		Q.pop();

		for (int i = 0; i < 8; i++)
		{
			int tx = x3 + dx[i];
			int ty = y3 + dy[i];
			if (is_valid(tx, ty))
			{
				Q.push({tx, ty});
				vis[tx][ty] = true;
				dis[tx][ty] = dis[x3][y3] + 1;
				if (tx == x2 && ty == y2) {
					found = true;
					break;
				}
			}
		}
		if (found)
			break;
	}
}
int main()
{
	int t;
	cin >> t;
	W(t)
	{
		char ch1, ch2;
		int x1, y1;
		cin >> ch1 >> x1 >> ch2 >> x2;
		y1 = ch1 - 96; y2 = ch2 - 96;

		bfs(x1, y1);
		cout << dis[x2][y2] << endl;
		memset(vis, false, sizeof(vis));
		memset(dis, 0, sizeof(dis));
	}

	return 0;
}