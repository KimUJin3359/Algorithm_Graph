#include <iostream>
#include <string>

int len;
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
char map[100][100];
int res_map[100][100] = { 987654321, };
bool visited[100][100];

void initialize()
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			visited[i][j] = false;
			res_map[i][j] = 987654321;
		}
	}
}

void fill_map(int r, int c, int res)
{
	int new_r;
	int new_c;
	int sum;

	if (r == len - 1 && c == len - 1)
	{
		if ()
	}
	for (int i = 0; i < 4; i++)
	{
		new_r = r + dr[i];
		new_c = c + dc[i];
		if (new_r >= 0 && new_r < len && new_c >= 0 && new_c < len && visited[new_r][new_c] == false)
		{
			sum = res + (map[new_r][new_c] - '0');
			if (sum > res_map[len - 1][len - 1])
				return;
			if (sum < res_map[new_r][new_c])
			{
				res_map[new_r][new_c] = sum;
				if (new_r == len - 1 && new_c == len - 1)
					return;
				visited[new_r][new_c] = true;
				fill_map(new_r, new_c, sum);
				visited[new_r][new_c] = false;
			}
		}
	}

}

int main()
{
	int C;

	ios::
	for (int N = 1; N <= C; N++)
	{
		scanf("%d", &len);
		initialize();
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
				scanf(" %c ", &map[i][j]);
		}
		visited[0][0] = true;
		res_map[0][0] = (map[0][0] - '0');
		fill_map(0, 0, res_map[0][0]);
		printf("#%d %d\n", N, res_map[len - 1][len - 1]);
	}
	return (0);
}