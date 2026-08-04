#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int col(vector<vector<int>>& robots){
    int colT = 0;
    map<vector<int>, int> pos;
    for(const vector<int>& po : robots)    pos[po]++;
    for(const auto& en : pos)
    {
        if(en.second>1)    colT++;
    }
    return colT;
}

void move(vector<vector<int>>& routes,vector<vector<int>>& robots,
          vector<int>& ro_tar,int& fin_rob,vector<vector<int>>& points){
    
    int n = routes[0].size();
    for(int i=0; i<robots.size(); ++i)
    {
        if(ro_tar[i] >= n)  continue;
        int tar = routes[i][ro_tar[i]]-1;

        if((ro_tar[i]<n)&&(robots[i][0]!=points[tar][0]))
        {
            if(robots[i][0]<points[tar][0])   robots[i][0]++;
            else if(robots[i][0]>points[tar][0])  robots[i][0]--;
        }
        else if((ro_tar[i]<n)&&(robots[i][1]!=points[tar][1]))
        {
            if(robots[i][1]<points[tar][1])   robots[i][1]++;
            else if(robots[i][1]>points[tar][1])  robots[i][1]--;
        }
        
        if((ro_tar[i]<n)&&(robots[i]==points[tar]))
        {
            ro_tar[i]++;
            if(ro_tar[i]==n)    fin_rob++;
            
        }
    }
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    vector<vector<int>> robots(routes.size(),vector<int>(2,0));
    for(int i=0; i<routes.size(); ++i)  robots[i]=points[routes[i][0]-1];
    answer += col(robots);
    
    vector<int> ro_tar(robots.size(),1);
    int fin_rob = 0;
    while(fin_rob!=robots.size())
    {
        move(routes,robots,ro_tar,fin_rob,points);
        answer += col(robots);
        for(int i = 0; i < robots.size(); ++i)
        {
            if(ro_tar[i] == routes[i].size())
            robots[i] = {-1, -i - 1};
        }
    }
    
    return answer;
}