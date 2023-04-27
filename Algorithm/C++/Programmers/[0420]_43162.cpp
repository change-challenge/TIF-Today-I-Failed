/*
	백준 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/43162
	난이도 : 3
	문제 이름 : 네트워크
*/

#include <string>
#include <vector>

using namespace std;

const int   MAX = 200;
bool        visited[MAX];

void    dfs(int total, int cur, vector<vector<int>> computers)
{
    visited[cur] = true;
    for (int i = 0; i < total; ++i)
    {
        if (computers[cur][i] == 1 && cur != i && visited[i] == false)
            dfs(total, i, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int     answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(n, i, computers);
            answer++;
        }
    }    
    return answer;
}