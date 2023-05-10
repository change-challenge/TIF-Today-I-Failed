/*
	백준 주소 : https://www.acmicpc.net/problem/1439
	난이도 : 실버5
	문제 이름 : 뒤집기
*/

#include <iostream>
#include <string>


int main()
{
	std::string	str;
	int			res[2] = {0, };
	std::cin >> str;


	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != str[i + 1 ])
		{
			if (str[i] == '0')
				res[0]++;
			else
				res[1]++;
		}
	}

	std::cout << (res[0] > res[1] ? res[1] : res[0]) << "\n";
}

