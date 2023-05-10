/*
	백준 주소 : https://www.acmicpc.net/problem/1520
	난이도 : 골드3
	문제 이름 : 내리막 길
*/

#include <iostream>

const int MAX = 500;

int		M, N;
int		map[MAX][MAX];
int		dp[MAX][MAX];
int		mx[4] = {0, 0, 1, -1};
int		my[4] = {1, -1, 0, 0};

int	dfs(int x, int y)
{
	if (x == N - 1 && y == M - 1)
		return 1;
	if (dp[y][x] != -1)
		return dp[y][x];
	dp[y][x] = 0;
	for (int i = 0 ; i < 4; i++)
	{
		int nx = x + mx[i];
		int ny = y + my[i];
		if (nx >= 0 && nx < N - 1 && ny >= 0 && ny < M - 1)
		{
			if (map[y][x] > map[ny][nx])
			{
				dp[y][x] += dfs(nx, ny);
			}
		}
	}
	return dp[y][x];
}

int main()
{
	std::cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
	std::cout << dfs(0, 0);
}
