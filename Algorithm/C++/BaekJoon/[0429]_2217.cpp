/*
	백준 주소 : https://www.acmicpc.net/problem/2217
	난이도 : 실버4
	문제 이름 : 로프
*/

#include <iostream>
#include <algorithm>
#include <vector>

int					NUM;
std::vector<int>	rope;

int main()
{
	std::cin >> NUM;

	for(int i = 0; i < NUM; i++)
	{
		int tmp;
		std::cin >> tmp;
		rope.push_back(tmp);
	}
	std::sort(rope.begin(), rope.end(), std::greater<int>());

	int res(0);
	for (int i = 0; i < NUM; i++)
	{
		int tmp = rope[i] * (i + 1);
		res = tmp > res ? tmp : res;
	}

	std::cout << res;
}