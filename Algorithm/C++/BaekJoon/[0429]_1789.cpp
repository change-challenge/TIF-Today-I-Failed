/*
	백준 주소 : https://www.acmicpc.net/problem/1789
	난이도 : 실버5
	문제 이름 : 수들의 합
*/

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	long long		num, total(0), res(0);
	std::cin >> num;

	while(total < num)
	{
		total = (res * (res + 1)) / 2;
		if (total > num)
			break ;
		res++;
	}
	std::cout << res - 1;
}