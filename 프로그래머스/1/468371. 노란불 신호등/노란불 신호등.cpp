#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> signals) {
    int answer = -1;
    int n = signals.size();
    int sec = 1;
    vector<int> s_len(n);
    for(int i=0; i<n; ++i)
    {
        s_len[i] = signals[i][0]+signals[i][1]+signals[i][2];
        sec = sec*s_len[i];
    }
    
    int d = 1;
    for(int j=2; j<20; ++j)
    {
        int x = 0;
        for(int k=0; k<n; ++k)
        {
            if(s_len[k]%j==0)   x++;
        }
        if(x==n)    d=j;
    }
    for(int z=0; z<n-1; ++z)  sec = sec/d;

    for(int l=1; l<=sec; ++l)
    {
        int y = 0;
        for(int m=0; m<n; ++m)
        {
            int sig = l%s_len[m];
            if(signals[m][0]<=sig&&(signals[m][1]>sig-signals[m][0]))   y++;
        }
        if(y==n)
        {
            answer = l;
            return answer+1;
        }
    }
    
    return answer;
}