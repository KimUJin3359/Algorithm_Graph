// 1. 자료형의 중요성
// 2. len[i][j] = (((long long)(point[j].first - point[i].first) * (long long)(point[j].first - point[i].first)) + ((long long)(point[j].second - point[i].second) * (long long)(point[j].second - point[i].second)));
// -> 자료형을 안 붙여주고 계산을 하면 자동적으로 int로 생각하고 하는듯
// 3. input, output 예시가 없었다면 반올림 몰랐을 듯

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

pair<int, int> point[1000];
int set[1000];
unsigned long long len[1000][1000];
long long res;

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return len[a.first][a.second] > len[b.first][b.second];
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int find_parent(int i)
{
	if (set[i] == -1)
		return (-1);
	if (set[i] == i)
		return (i);
	find_parent(set[i]);
}

int main()
{
	int C;
	int num;
	int vertex;
	double rate;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		res = 0;
		cin >> num;
		vertex = num - 1;
		for (int i = 0; i < num; i++)
		{
			cin >> point[i].first;
			set[i] = -1;
		}
		for (int i = 0; i < num; i++)
			cin >> point[i].second;
		cin >> rate;
		for (int i = 0; i < num; i++)
		{
			for (int j = i + 1; j < num; j++)
			{
				len[i][j] = (((long long)(point[j].first - point[i].first) * (long long)(point[j].first - point[i].first)) + ((long long)(point[j].second - point[i].second) * (long long)(point[j].second - point[i].second)));
				pq.push({ i, j });
			}
		}
		while (vertex)
		{
			//select
			if (find_parent(pq.top().first) == -1 || find_parent(pq.top().second) == -1 ||
				find_parent(pq.top().first) != find_parent(pq.top().second))
			{
				//printf("[%d, %d], [%d, %d] : %ld\n", point[pq.top().first].first, point[pq.top().first].second, point[pq.top().second].first, point[pq.top().second].second, len[pq.top().first][pq.top().second]);
				if (find_parent(pq.top().first) == -1)
					set[pq.top().first] = pq.top().first;
				if (find_parent(pq.top().second) == -1)
					set[pq.top().second] = find_parent(pq.top().first);
				else
					set[find_parent(pq.top().second)] = find_parent(pq.top().first);
				vertex--;
				res += len[pq.top().first][pq.top().second];
			}
			pq.pop();
		}
		res = (long long)round((long double)(res *rate));
		printf("#%d %ld\n", N, res);
		while (pq.size())
			pq.pop();
	}
	return (0);
}