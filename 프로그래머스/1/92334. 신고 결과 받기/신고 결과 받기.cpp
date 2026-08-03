#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int n = id_list.size();
    vector<int> answer(n,0);
    //~가 ~에게 [가][에게]
    vector<vector<int>> reported(n,vector<int>(n,0));
    for(int i=0; i<report.size(); ++i)
    {
        int pos = report[i].find(' ');
        string rep = report[i].substr(0, pos);
        string reped = report[i].substr(pos + 1);
        
        auto rep_it = find(id_list.begin(), id_list.end(), rep);
        int index_rep = rep_it - id_list.begin();
        auto reped_it = find(id_list.begin(), id_list.end(), reped);
        int index_reped = reped_it - id_list.begin();
        reported[index_rep][index_reped] = 1;
    }
    
    for(int j=0; j<n; ++j)
    {
        int tot = 0;
        for(int l=0; l<n; ++l) tot+=reported[l][j];
        if(tot>=k)
        {
            for(int m=0; m<n; ++m)
            {
                if(reported[m][j]>0)    answer[m]++;
            }
        }
    }
    
    
    return answer;
}