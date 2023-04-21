/*
	백준 주소 : https://www.acmicpc.net/problem/11399
	난이도 : 실버4
	문제 이름 : ATM
*/

#include <iostream>
#include <vector>
#include <algorithm>

int	NUM;
std::vector<int>	arr;

int main()
{
	int res(0);
	std::cin >> NUM;

	arr.push_back(0);
	for (int i = 0; i < NUM; i++)
	{
		int tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}
	std::sort(arr.begin(), arr.end());
	
	for (int i = 1; i <= NUM; i++)
	{
		//std::cout << arr[i] << std::endl;
		arr[i] += arr[i - 1];
		res += arr[i];
	}

	std::cout << res << std::endl;
}
