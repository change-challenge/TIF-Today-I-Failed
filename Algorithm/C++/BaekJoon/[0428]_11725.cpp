/*
	백준 주소 : https://www.acmicpc.net/problem/11725
	난이도 : 실버2
	문제 이름 : 트리의 부모 찾기
*/

#include <iostream>
#include <vector>
#include <queue>

const int						MAX = 100001;
int								NUM;
bool							visited[MAX];
int								parent[MAX];
std::vector<int>				v[MAX];

void	bfs(void)
{
	std::queue<int>	q;
	q.push(1);
	visited[1] = true;

	while(!q.empty())
	{
		int size = q.size();
		//std::cout << "size : " << size << std::endl;
		while(size--)
		{
			int front = q.front(); 
			//std::cout << "front : " << front << std::endl;
			q.pop();
			visited[front] = true;
			for (int i = 0; i < v[front].size(); i++)
			{
				if (!visited[v[front][i]])
				{
					q.push(v[front][i]);
					parent[v[front][i]] = front;
				}
			}
		}
	}

}

int main()
{
	std::cin >> NUM;
	for (int i = 1; i < NUM; i++)
	{
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs();
	for (int i = 2; i <= NUM; i++)
	{
		std::cout << parent[i] << "\n";
	}
}
