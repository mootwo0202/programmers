#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    //축 위
    answer+=r2-r1+1;
    //평면 위
    for(long long i=1; i<r2; ++i)
    {
        if(i<r1)
        {
            answer+=floor(sqrt(1ll*r2*r2-1ll*i*i))-floor(sqrt(1ll*r1*r1-1ll*i*i));
            if(floor(sqrt(1ll*r1*r1-1ll*i*i))==sqrt(1ll*r1*r1-1ll*i*i)) answer++;
        }
        else    answer+=floor(sqrt(1ll*r2*r2-1ll*i*i));
    }
    
    return answer*4;
}