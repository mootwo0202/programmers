#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    // y=0
    answer+=(d/k)+1;
    //y>0
    for(int i=0; i<=(d/k); ++i)
    {
        long long x = 1ll*k*i;
        long long h = sqrt(1l*d*d-1ll*x*x);
        answer+=h/k;
    }
    return answer;
}