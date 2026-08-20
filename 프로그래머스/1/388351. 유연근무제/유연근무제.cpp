#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int i=0; i<schedules.size(); ++i)
    {
        int time = schedules[i]+10;
        if((time%100)>=60)   time+=40;
        int day=startday;
        int pass=0;
        for(int j=0; j<7; ++j)
        {
            if((day!=6)&&(day!=7))
            {
                if(timelogs[i][j]<=time)    pass++;
            }
            day++;
            if(day>7)   day=1;
        }
        if(pass==5) answer++;
    }
    
    return answer;
}