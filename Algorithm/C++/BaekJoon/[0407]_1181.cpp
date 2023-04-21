/*
	백준 주소 : https://www.acmicpc.net/problem/43165
	난이도 : 2
	문제 이름 : 타켓 넘버
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int     answer;
int     numbers_size;
bool    visited[50];

void    dfs(int cnt, int res, const int& target, const vector<int>& numbers)
{
    if (cnt == numbers_size)
    {
        if (res == target)
        {
            answer++;
        }
        return ;
    }
    dfs(cnt + 1, res + numbers[cnt], target, numbers);
    dfs(cnt + 1, res - numbers[cnt], target, numbers);
}


int solution(vector<int> numbers, int target) {
    
    numbers_size = numbers.size();
    dfs(0, 0, target, numbers);
    return answer;
}