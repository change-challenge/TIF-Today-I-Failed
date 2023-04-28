/*
	백준 주소 : https://www.acmicpc.net/problem/1026
	난이도 : 실버4
	문제 이름 : 보물
*/

#include <iostream>
#include <algorithm>
#include <vector>

int			NUM;
std::vector<int>	first;
std::vector<int>	second;


int main()
{
	std::cin >> NUM;

	for (int i = 0; i < NUM; i++)
	{
		int tmp;
		std::cin >> tmp;
		first.push_back(tmp);
	}
	for (int i = 0; i < NUM; i++)
	{
		int tmp;
		std::cin >> tmp;
		second.push_back(tmp);
	}

	std::sort(first.begin(), first.end(), std::greater<int>());
	std::sort(second.begin(), second.end());

	int res(0);
	for (int i = 0; i < NUM; i++)
	{
		res += (first[i] * second[i]);
	}
	std::cout << res << "\n";
}