/*
	백준 주소 : https://www.acmicpc.net/problem/11047
	난이도 : 실버4
	문제 이름 : 동전 0
*/

#include <iostream>
#include <vector>
#include <algorithm>

int			N, K;
const int	MAX = 10;
int			money[MAX];

int	total_money(void)
{
	int res(0);
	while (K)
	{
		while (K < money[N - 1])
			N--;
		K -= money[N - 1];
		res++;
	}
	return res;
}

int main()
{
	std::cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		std::cin >> money[i];
	}

	std::cout << total_money() << "\n";
}
