/*
	백준 주소 : https://www.acmicpc.net/problem/1715
	난이도 : 골드4
	문제 이름 : 카드 정렬하기
*/

#include <iostream>
#include <queue>

int main()
{
	int							num;
	long long					res(0);
	std::priority_queue<int, std::vector<int>, std::greater<int> >	q;

	std::cin >> num;

	for(int i = 0 ; i < num; i++)
	{
		int tmp;
		std::cin >> tmp;
		q.push(tmp);
	}
	while(q.size() != 1)
	{
		int num1 = q.top(); q.pop();
		int num2 = q.top(); q.pop();
		res += (num1 + num2);
		q.push(num1 + num2);
	}
	std::cout << res;	
}