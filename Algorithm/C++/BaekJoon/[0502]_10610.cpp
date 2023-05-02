/*
	백준 주소 : https://www.acmicpc.net/problem/10610
	난이도 : 실버4
	문제 이름 : 30
*/

#include <iostream>
#include <algorithm>
#include <string>

int main()
{
	std::string	num_st;
	std::cin >> num_st;

	std::sort(num_st.begin(), num_st.end(), std::greater<int>());
	if (num_st[num_st.size() - 1] != '0')
		std::cout << -1;
	else 
	{
		long long	sum(0);
		for (int i = 0; i < num_st.size() - 1; i++)
			sum += num_st[i] - '0';
		if (sum % 3 == 0)
			std::cout << num_st;
		else
			std::cout << -1;
	}
	return 0;
}