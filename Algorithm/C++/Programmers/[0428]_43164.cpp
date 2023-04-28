/*
	백준 주소 : https://www.acmicpc.net/problem/43164
	난이도 : 3
	문제 이름 : 여행 경로
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string>  answer;
bool            visited[10000];

bool    compare(vector<string> a, vector<string> b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

void    dfs(string target, const vector<vector<string>>& tickets) 
{
    std::cout << target << std::endl;
    if (tickets.size() == answer.size())
    {
        answer.push_back(target);
        return ;
    }
    for (int i = 0 ; i < tickets.size(); i++)
    {
        if (tickets[i][0] == target && !visited[i])
        {
            visited[i] = true;
            answer.push_back(target);
            dfs(tickets[i][1], tickets);
            if (answer.size() == tickets.size() + 1)
                return ;
            answer.pop_back();
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), compare);
    dfs("ICN", tickets);
    return answer;
}