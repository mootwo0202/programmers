#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// graph[node] = {인접 노드, 파이프 타입}
void spreadVirus(int type,vector<int>& infected,
                 const vector<vector<pair<int, int>>>& graph){
    int n = graph.size();

    // 현재 감염된 모든 노드를 BFS 시작점으로 사용
    vector<int> q;

    for(int i = 0; i < n; ++i)
    {
        if(infected[i] == 1)
            q.push_back(i);
    }

    int front = 0;

    while(front < q.size())
    {
        int current = q[front++];

        for(const pair<int, int>& edge : graph[current])
        {
            int next = edge.first;
            int edgeType = edge.second;

            // 지금 연 파이프 타입만 이동 가능
            if(edgeType != type)
                continue;

            if(infected[next] == 0)
            {
                infected[next] = 1;
                q.push_back(next);
            }
        }
    }
}

void search(int depth,int k,const vector<int>& infected,
    const vector<vector<pair<int, int>>>& graph,int& answer){
    int infectedCount = 0;

    for(int state : infected)
    {
        if(state == 1)  infectedCount++;
    }

    answer = max(answer, infectedCount);

    // 전부 감염시켰거나 행동을 k번 사용한 경우
    if(answer == graph.size() || depth == k)
        return;

    // 다음 행동으로 A, B, C를 각각 선택
    for(int type = 1; type <= 3; ++type)
    {
        vector<int> nextInfected = infected;

        spreadVirus(type, nextInfected, graph);

        // 감염 상태가 바뀌지 않는 행동은 사용할 필요가 없음
        if(nextInfected == infected)    continue;

        search(depth + 1,k,nextInfected,graph,answer);
    }
}

int solution(int n,int infection,vector<vector<int>> edges,int k){
    vector<vector<pair<int, int>>> graph(n);

    for(const vector<int>& edge : edges)
    {
        int x = edge[0] - 1;
        int y = edge[1] - 1;
        int type = edge[2];

        graph[x].push_back({y, type});
        graph[y].push_back({x, type});
    }

    vector<int> infected(n, 0);
    infected[infection - 1] = 1;

    int answer = 1;

    search(0,k,infected,graph,answer);

    return answer;
}