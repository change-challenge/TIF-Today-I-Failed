/*
	백준 주소 : https://www.acmicpc.net/problem/10162
	난이도 : 브론즈3
	문제 이름 : 전자렌인지
*/

#include <iostream>

int main()
{
	int time;
	int timers[3] = {300, 60, 10};
	int res[3] = {0, };

	std::cin >> time;

	int idx(0);
	while (idx < 3 && time > 0)
	{
		if (time < timers[idx])
		{
			idx++;
			continue;
		}
		time -= timers[idx];
		res[idx]++;
	}

	if (time == 0)
	{
		std::cout << res[0] << " ";
		std::cout << res[1] << " ";
		std::cout << res[2];
	}
	else
		std::cout << -1;


}