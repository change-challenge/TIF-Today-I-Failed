/*
	백준 주소 : https://www.acmicpc.net/problem/169199
	난이도 : 2
	문제 이름 : 리코쳇 로봇
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 101;
pair<int, int>  sp;
bool            visited[101][101];

void    find_sp(const vector<string>& board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'R')
            {
                sp = make_pair(j, i);
                break;
            }
        }
    }
}

int bfs(const vector<string>& board)
{
    int res(0);
    queue<pair<int, int> > q;
    q.push(sp);
    visited[sp.second][sp.first] = true;
    while(!q.empty())
    {
        int size = q.size();
		cout << "size : " << size << endl;
        while (size--)
        {
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            
			std::cout << "x : " << cur_x << " | y : " << cur_y << std::endl;
		
            if (board[cur_y][cur_x] == 'G')
                return res;
            
            while (cur_x - 1 >= 0 && board[cur_y][cur_x - 1] != 'D')
                cur_x--;
            if (cur_x != q.front().first && !visited[cur_y][cur_x])
            {
                visited[cur_y][cur_x] = true;
				//std::cout << "visited[" << cur_y << "][" << cur_x << "] !! " << endl;
                q.push(make_pair(cur_x, cur_y));
            }
            while (cur_x + 1 < board[0].size() && board[cur_y][cur_x + 1] != 'D')
                cur_x++;
            if (cur_x != q.front().first && !visited[cur_y][cur_x])
            {
                visited[cur_y][cur_x] = true;
                q.push(make_pair(cur_x, cur_y));
            }
			cur_x = q.front().first;

            // y
            while (cur_y - 1 >= 0 && board[cur_y - 1][cur_x] != 'D')
                cur_y--;
            if (cur_y != q.front().second && !visited[cur_y][cur_x])
            {
                visited[cur_y][cur_x] = true;
                q.push(make_pair(cur_x, cur_y));
            }
            while (cur_y + 1 < board.size() && board[cur_y + 1][cur_x] != 'D')
                cur_y++;
            if (cur_y != q.front().second && !visited[cur_y][cur_x])
            {
                visited[cur_y][cur_x] = true;
                q.push(make_pair(cur_x, cur_y));
            }
            q.pop();
        }
        res++;
    }
    return -1;
}

int solution(const vector<string>& board) {
	cout << "============solution started============\n";
    find_sp(board);
    return bfs(board);
}

int main()
{
	int NUM;
	cin >> NUM;
	vector<string> board;


	for (int i = 0; i < NUM; i++)
	{
		string tmp;
		cin >> tmp;
		board.push_back(tmp);
	}
	std::cout << "solution is : " << solution(board) << endl;
}