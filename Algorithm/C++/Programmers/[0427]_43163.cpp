/*
	백준 주소 : https://www.acmicpc.net/problem/43163
	난이도 : 2
	문제 이름 : 단어 정렬
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 50;
bool    visited[MAX];

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    if (find(words.begin(), words.end(), target) == words.end())
        return 0;

	int	words_len = words.size();
	int	words_size = words[0].size();
    queue<string> q;
    q.push(begin);
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            string tmp = q.front();
            q.pop();
            if (tmp == target)
                return answer;
            for (int i = 0; i < words_len; i++)
            {
                int cnt(0);
                for(int j = 0; j < words_size; j++)
                {
                    if (tmp[j] != words[i][j])
                        cnt++;
                }
                if (cnt >= 2)
                    continue;
                q.push(words[i]);
                visited[i] = true;
            }
        }
        answer++;
    }
    return 0;
}