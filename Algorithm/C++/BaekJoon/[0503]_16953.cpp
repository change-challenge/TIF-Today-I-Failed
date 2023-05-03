/*
	백준 주소 : https://www.acmicpc.net/problem/16953
	난이도 : 실버2
	문제 이름 : A -> B
*/

#include <iostream>
#include <queue>
#include <string>

int start, target;

int	bfs(void)
{
	int res(1);
	std::queue<long>	q;
	q.push(start);

	while (!q.empty())
	{
		int size = q.size();
		//std::cout << "==============size : " << size << "\n";
		while(size--)
		{
			long front = q.front(); q.pop();
			//std::cout << "front " << front << std::endl;
			if (front == target)
				return res;
			long long tmp1 = front * 2;
			long long tmp2 = stoll(std::to_string(front) + "1");
			if (tmp1 <= target)
				q.push(tmp1);
			if (tmp2 <= target)
				q.push(tmp2);
		}
		res++;
	}
	return -1;
}

int main()
{
	std::cin >> start >> target;

	std::cout << bfs() << "\n";	
}
