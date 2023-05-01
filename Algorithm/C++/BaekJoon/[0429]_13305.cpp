/*
	백준 주소 : https://www.acmicpc.net/problem/13305
	난이도 : 실버3
	문제 이름 : 주유소
*/

#include <iostream>

const int			MAX = 100001;
unsigned long long	dis[MAX];
unsigned long long	city_oil[MAX];

int main()
{
	int					num;
	unsigned long long	res(0);
	std::cin >> num;

	for (int i = 0; i < num - 1; i++)
	{
		std::cin >> dis[i];
	}
	for (int i = 0; i <= num - 1; i++)
	{
		std::cin >> city_oil[i];
	}

	int tmp_oil = city_oil[0];
	res = dis[0] * city_oil[0];
	for (int i = 1; i < num - 1; i++)
	{
		if (city_oil[i] < tmp_oil)
		{
			tmp_oil = city_oil[i];
		}
		res += tmp_oil * dis[i];
	}

	std::cout << res;
}