/*
	백준 주소 : https://www.acmicpc.net/problem/10610
	난이도 : 실버4
	문제 이름 : 30
*/

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string	num;
	std::cin >> num;

	if (std::find(num.begin(), num.end(), '0') == num.end())
	{
		std::cout << -1;
		return 0;
	}

	std::sort(num.begin(), num.end(), std::greater<char>());
	
	//while (true)
	//{
	//	if (int(n))
	//}
	std::cout << static_cast<int>(num) << std::endl;
	//3 6 9 
	//12 15 18 
	//21 24 27 30

	//33 36 39
	//42 

}