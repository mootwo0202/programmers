#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> move(vector<int> answer, int k,
                 vector<vector<int>>& table,
                 vector<string>& routes)
{
    int x = answer[0];
    int y = answer[1];

    int dist = stoi(routes[k].substr(2));

    if(routes[k][0] == 'E')
    {
        for(int i = 1; i <= dist; ++i)
        {
            int nx = x + i;

            if(nx >= table[0].size())
                return answer;

            if(table[y][nx] == 1)
                return answer;
        }

        x += dist;
    }

    else if(routes[k][0] == 'W')
    {
        for(int i = 1; i <= dist; ++i)
        {
            int nx = x - i;

            if(nx < 0)
                return answer;

            if(table[y][nx] == 1)
                return answer;
        }

        x -= dist;
    }

    else if(routes[k][0] == 'N')
    {
        for(int i = 1; i <= dist; ++i)
        {
            int ny = y - i;

            if(ny < 0)
                return answer;

            if(table[ny][x] == 1)
                return answer;
        }

        y -= dist;
    }

    else if(routes[k][0] == 'S')
    {
        for(int i = 1; i <= dist; ++i)
        {
            int ny = y + i;

            if(ny >= table.size())
                return answer;

            if(table[ny][x] == 1)
                return answer;
        }

        y += dist;
    }

    return {x, y};
}

vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> answer;

    vector<vector<int>> table(
        park.size(),
        vector<int>(park[0].size(), 0)
    );

    for(int i = 0; i < park.size(); ++i)
    {
        for(int j = 0; j < park[0].size(); ++j)
        {
            if(park[i][j] == 'S')
            {
                answer = {j, i};
                table[i][j] = 0;
            }
            else if(park[i][j] == 'O')
            {
                table[i][j] = 0;
            }
            else
            {
                table[i][j] = 1;
            }
        }
    }

    for(int k = 0; k < routes.size(); ++k)
        answer = move(answer, k, table, routes);

    // 문제에서 요구하는 순서는 [세로, 가로]
    return {answer[1], answer[0]};
}