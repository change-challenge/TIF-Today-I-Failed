/*
	백준 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/1844
	난이도 : 2
	문제 이름 : 게임 맵 최단거리
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int   MAX = 100;

bool                    visited[MAX][MAX];
queue<pair<int, int> >  q;

int    bfs(vector<vector<int> > map, int res)
{
    int total_x = map[0].size();
    int total_y = map.size();
        
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            q.pop();
            if (cur_x == total_x - 1 && cur_y == total_y - 1)
                return res;
            if (cur_x + 1 < total_x && visited[cur_y][cur_x + 1] == false && map[cur_y][cur_x + 1] == 1)
            {
                visited[cur_y][cur_x + 1] = true;
                q.push(make_pair(cur_x + 1, cur_y));
            }
            if (cur_y + 1 < total_y && visited[cur_y + 1][cur_x] == false && map[cur_y + 1][cur_x] == 1)
            {
                visited[cur_y + 1][cur_x] = true;
                q.push(make_pair(cur_x, cur_y + 1));
            }
            if (cur_x - 1 >= 0 && visited[cur_y][cur_x - 1] == false && map[cur_y][cur_x - 1] == 1)
            {
                visited[cur_y][cur_x - 1] = true;
                q.push(make_pair(cur_x - 1, cur_y));
            }
            if (cur_y - 1 >= 0 && visited[cur_y - 1][cur_x] == false && map[cur_y - 1][cur_x] == 1)
            {
                visited[cur_y - 1][cur_x] = true;
                q.push(make_pair(cur_x, cur_y - 1));
            }
        }
        res++;
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{    
    q.push(make_pair(0, 0));
    visited[0][0] = true;

    return bfs(maps, 1);
}