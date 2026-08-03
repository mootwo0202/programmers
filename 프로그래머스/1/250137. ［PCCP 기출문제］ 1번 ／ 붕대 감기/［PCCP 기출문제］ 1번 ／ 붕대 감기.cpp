#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int last_time = attacks[attacks.size()-1][0];
    int max_health = health;
    int cnt_h = 0;
    int cnt_a = 0;
    for(int i=1; i<=last_time; ++i)
    {
        if(attacks[cnt_a][0]==i)
        {
            cnt_h=0;
            health-=attacks[cnt_a][1];
            if(health<1)    return -1;
            cnt_a++;
        }
        else
        {
            if(health<max_health)
            {
                health+=bandage[1];
                cnt_h++;
            }
            if(cnt_h==bandage[0])
            {
                health+=bandage[2];
                cnt_h=0;
            }
            if(health>max_health)  health=max_health;
        }
    }
    
    
    return health;
}