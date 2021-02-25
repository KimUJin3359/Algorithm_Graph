#include <iostream>
#include <string>
#include <queue>
#define MAX 987654321
using namespace std;

int len;
bool check[100][100];
int map[100][100];
int di_map[100][100];

struct compare{
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return di_map[a.first][a.second] > di_map[b.first][b.second];
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
pair<int, int> min_p;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void dijkstra(int r, int c)
{
	int new_r;
	int new_c;
	int min = MAX;

	for (int i = 0; i < 4; i++)
	{
		new_r = r + dr[i];
		new_c = c + dc[i];

		if (new_r >= 0 && new_r < len && new_c >= 0 && new_c < len)
		{
			pq.push({ new_r, new_c });
			if (di_map[r][c] + map[new_r][new_c] < di_map[new_r][new_c])
				di_map[new_r][new_c] = di_map[r][c] + map[new_r][new_c];
		}
	}
	while (check[pq.top().first][pq.top().second] == true)
		pq.pop();
	min_p.first = pq.top().first;
	min_p.second = pq.top().second;
	if (min_p.first == len - 1 && min_p.second == len - 1)
	{
		while (pq.size())
			pq.pop();
		return;
	}
	check[min_p.first][min_p.second] = true;
	dijkstra(min_p.first, min_p.second);
}

int main()
{
	int C;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		string input;
		
		cin >> len;
		for (int i = 0; i < len; i++)
		{
			cin >> input;
			for (int j = 0; j < len; j++)
			{
				map[i][j] = input[j] - '0';
				di_map[i][j] = MAX;
				check[i][j] = false;
			}
		}
		di_map[0][0] = map[0][0];
		check[0][0] = true;
		dijkstra(0, 0);
		printf("#%d %d\n", N, di_map[len - 1][len - 1]);
	}
	return (0);
}