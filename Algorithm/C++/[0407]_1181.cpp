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
    //v.erase(std::unique(v.begin(), v.end()), v.end());
    std::sort(v.begin(), v.end(), compare);
	for (int i = 0; i < num; ++i)
	{
		if (v[i] == v[i + 1])
			continue;
		std::cout << v[i] << std::endl;
	}

	//std::cout << "====================================\n";
    //std::set<std::string>		res(v.begin(), v.end());
    //for (std::set<std::string>::const_iterator it = res.begin(); it != res.end(); ++it)
	//{
	//	std::cout << *it << std::endl;
	//}
}