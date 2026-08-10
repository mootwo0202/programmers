#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cal(vector<int> a, vector<int> r){
    int a_score = 0;
    int r_score = 0;
    for(int i=0; i<10; ++i)
    {
        if(a[i]>0||r[i]>0)
        {
            if(a[i]>=r[i])  a_score+=10-i;
            else    r_score+=10-i;
        } 
    }
    
    return r_score-a_score;
}

bool lowerScoreMore(const vector<int>& candidate,
                    const vector<int>& current)
{
    for(int i = 10; i >= 0; --i)
    {
        if(candidate[i] > current[i])
            return true;

        if(candidate[i] < current[i])
            return false;
    }

    return false;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    int score = -1;
    
    for(int i=0; i<1024; ++i)
    {
        vector<int> r_table(11,0);
        int cnt = i;
        int n_cnt=n;
        for(int j=0;j<10;++j)
        {
            int cnt_num = 1<<(9-j);
            if((cnt>=cnt_num)&&(n_cnt>info[j]))
            {
                r_table[j]=info[j]+1;
                n_cnt-=r_table[j];
            }
            if(cnt>=cnt_num)   cnt-=cnt_num;
        }
        r_table[10]=n_cnt;
        
        int x = cal(info,r_table);
        
        if(answer.empty() || x > score)
        {
            score = x;
            answer = r_table;
        }
        else if(x == score && lowerScoreMore(r_table, answer))   answer = r_table;
        
    }
    
    if(score <= 0)  return {-1};

    return answer;
    
       
}