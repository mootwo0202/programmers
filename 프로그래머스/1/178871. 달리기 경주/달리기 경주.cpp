#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    
    unordered_map<string, int> rank;

    for(int i = 0; i < players.size(); ++i) rank[players[i]] = i;

    for(int i = 0; i < callings.size(); ++i)
    {
        string name = callings[i];
        int cur = rank[name];

        string front = players[cur - 1];

        players[cur - 1] = name;
        players[cur] = front;

        rank[name] = cur - 1;
        rank[front] = cur;
    }

    return players;
}