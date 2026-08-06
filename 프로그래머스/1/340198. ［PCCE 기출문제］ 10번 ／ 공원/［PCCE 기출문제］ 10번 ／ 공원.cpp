#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    sort(mats.begin(),mats.end());
    int x_len = park[0].size();
    int y_len = park.size();
    int size = x_len*y_len;
    for(int i=0; i<mats.size(); ++i)
    {
        int x = mats[mats.size()-i-1];
        vector<string> tab(x,"-1");
        for(int j=0; j<=y_len-x; ++j)
        {
            for(int k=0; k<=x_len-x; ++k)
            {
                vector<string> part(park[j].begin()+k,park[j].begin()+k+x);
                if(tab==part)
                {
                    int cnt = 1;
                    for(int l=1; l<x; ++l)
                    {
                        vector<string> part1(
                            park[j+l].begin()+k,park[j+l].begin()+k+x);
                        if(tab==part1)  cnt++;
                    }
                    if(cnt == x)    return x;
                }
            }
        }
        
    }

    
    return -1;
}