/*
	백준 주소 : https://www.acmicpc.net/problem/1541
	난이도 : 실버2
	문제 이름 : 잃어버린 괄호
*/

#include <iostream>
#include <cctype>
#include <string>
#include <vector>

int main()
{
	std::string			exp;
	std::vector<int>	numbers;
	int					res(0), tmp(0);
	bool				m_flag = false;
	std::cin >> exp;

	for(int i = 0 ; i < exp.size(); i++)
	{
		if (isdigit(exp[i]))
		{
			tmp = (tmp * 10) + (exp[i] - '0');
		}
		else if (exp[i] == '-' && m_flag == false)
		{
			numbers.push_back(tmp);
			m_flag = true;
			tmp = 0;
			continue;
		}
		if (exp[i] == '-' || exp[i] == '+' || i == exp.size() - 1)
		{
			if (m_flag == false)
				numbers.push_back(tmp);
			else
				numbers.push_back(-1 * tmp);
			tmp = 0;
		}
	}

	for (int i = 0; i < numbers.size(); i++)
	{
		res += numbers[i];
	}

	std::cout << res << "\n";	
}
