/*
	백준 주소 : https://www.acmicpc.net/problem/1520
	난이도 : 골드3
	문제 이름 : 내리막 길
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

const int MAX = 500;

int		M, N;
int		map[MAX][MAX];
int		visited[MAX][MAX];


int	bfs(int x, int y)
{
	int									res(0), max(0);
	std::queue<std::pair<int, int> >	q;

	q.push(std::make_pair(x, y));
	visited[y][x]++;
	while(!q.empty())
	{
		int size = q.size();
		max = size > max ? size : max;
		//std::cout << "========size : " << size << "\n";
		while(size--)
		{
			int m_x = q.front().first;
			int m_y = q.front().second;
			q.pop();
			//std::cout << "m_x : " << m_x << " m_y : "<< m_y << " => " << map[m_y][m_x] <<  "\n";

			if (m_x == N - 1 && m_y == M - 1)
			{
				res++;
				continue;
			}
			if (m_x + 1 < N && visited[m_y][m_x + 1] <= max && map[m_y][m_x + 1] < map[m_y][m_x])
			{
				q.push(std::make_pair(m_x + 1, m_y));
				visited[m_y][m_x + 1]++;
			}
			if (m_y + 1 < M && visited[m_y + 1][m_x] <= max && map[m_y + 1][m_x] < map[m_y][m_x])
			{
				q.push(std::make_pair(m_x, m_y + 1));
				visited[m_y + 1][m_x]++;
			}
			if (m_x - 1 >= 0 && visited[m_y][m_x - 1] <= max && map[m_y][m_x - 1] < map[m_y][m_x])
			{
				q.push(std::make_pair(m_x - 1, m_y));
				visited[m_y][m_x - 1]++;
			}
			if (m_y - 1 >= 0 && visited[m_y - 1][m_x] <= max && map[m_y - 1][m_x] < map[m_y][m_x])
			{
				q.push(std::make_pair(m_x, m_y - 1));
				visited[m_y - 1][m_x]++;
			}
		}
	}
	return res;
}

int main()
{
	std::cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> map[i][j];
		}
	}
	std::cout << bfs(0, 0);
}
