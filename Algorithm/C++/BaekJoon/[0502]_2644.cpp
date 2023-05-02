/*
	백준 주소 : https://www.acmicpc.net/problem/2644
	난이도 : 실버2
	문제 이름 : 촌수계산
*/

#include <iostream>
#include <vector>
#include <queue>

const int MAX = 100;

//int					people[MAX];
bool				visited[MAX];
int					people_num, t_a, t_b, edge;
std::vector<int>	relation[MAX];

int	bfs(void)
{
	int				res(0);
	std::queue<int>	q;

	q.push(t_a);
	visited[t_a] = true;
	while(!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			int tmp = q.front();
			q.pop();
			if (tmp == t_b)
				return res;
			for(int i = 0 ; i < relation[tmp].size(); i++)
			{
				if (!visited[relation[tmp][i]])
				{
					q.push(relation[tmp][i]);
					visited[relation[tmp][i]] = true;
				}
			}
		}
		res++;
	}
	return -1;
}

int main()
{
	std::cin >> people_num >> t_a >> t_b >> edge;

	relation->resize(people_num, 0);
	for (int i = 0; i < edge; i++)
	{
		int a, b;
		std::cin >> a >> b;
		relation[a].push_back(b);
		relation[b].push_back(a);
	}
	std::cout << bfs();
}