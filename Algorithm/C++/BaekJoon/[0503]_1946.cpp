/*
	백준 주소 : https://www.acmicpc.net/problem/1946
	난이도 : 실버1
	문제 이름 : 신입 사원
*/

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int test_num;

	std::cin >> test_num;

	while (test_num--)
	{
		std::vector<std::pair<int, int> >	grade;
		int worker_num, tmp1, tmp2;
		std::cin >> worker_num;
		for (int i = 0 ; i < worker_num; i++)
		{
			std::cin >> tmp1 >> tmp2;
			grade.push_back(std::make_pair(tmp1, tmp2));
		}
		std::sort(grade.begin(), grade.end());
		int tmp(0), res(1);
		for (int i = 1 ; i < worker_num; i++)
		{
			if (grade[tmp].second > grade[i].second)
			{
				res++;
				tmp = i;
			}
		}
		std::cout << res << "\n";
		grade.clear();
	}
}
