/*
	백준 주소 : https://www.acmicpc.net/problem/1181
	난이도 : 2
	문제 이름 : 단어 정렬
*/

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

bool    compare(const std::string& s1, const std::string& s2)
{
    if (s1.size() == s2.size())
    {
        return s1 < s2;
    }
    return (s1.size() < s2.size());
}

int main()
{
    int num;
	std::vector<std::string>	v;
    std::cin >> num;
    
    for (int i = 0; i < num; i++)
    {
		std::string tmp;
		std::cin >> tmp;
		v.push_back(tmp);
    }
    std::sort(v.begin(), v.end(), compare);
	for (int i = 0; i < num; ++i)
	{
		if (v[i] == v[i + 1])
			continue;
		std::cout << v[i] << std::endl;
	}

}