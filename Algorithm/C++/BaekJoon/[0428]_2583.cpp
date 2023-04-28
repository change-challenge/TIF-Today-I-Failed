/*
	백준 주소 : https://www.acmicpc.net/problem/2583
	난이도 : 실버1
	문제 이름 : 영역 구하기
*/

#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 100;
int					m_x[4] = {1, -1, 0, 0};
int					m_y[4] = {0, 0, 1, -1};
int					Y, X, NUM;
bool				visited[MAX][MAX];

int	dfs(int x, int y, int& res)
{
	res++;
	visited[y][x] = true;
	for(int i = 0 ; i < 4; i++)
	{
		if (x + m_x[i] >= 0 && x + m_x[i] < X && y + m_y[i] >= 0 && y + m_y[i] < Y
			&& !visited[y + m_y[i]][x + m_x[i]])
			{
				dfs(x + m_x[i], y + m_y[i], res);
			}
	}
	return res;
}

int main()
{
	int res(0);
	std::vector<int>	total_res;

	std::cin >> Y >> X >> NUM;
	
	for (int i = 0; i < NUM; i++)
	{
		int f_x, f_y, l_x, l_y;
		std::cin >> f_x >> f_y >> l_x >> l_y;
		for (int i = f_y; i < l_y; i++)
		{
			for (int j = f_x; j < l_x; j++)
			{
				visited[i][j] = true;
			}
		}
	}
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			int tmp(0);
			if (!visited[i][j])
			{
				total_res.push_back(dfs(j, i, tmp));
				res++;
			}
		}
	}

	std::cout << res << "\n";
	std::sort(total_res.begin(), total_res.end());
	for (std::vector<int>::iterator it = total_res.begin(); it != total_res.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
}
