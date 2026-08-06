#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int box(vector<bool>& open,vector<int>& cards,bool& fin){
    int s = 0,cnt=1;
    while((s<open.size())&&(open[s]==true))   s++;
    
    if(s==open.size())
    {
        fin=true;
        return 0;
    }
    else
    {
        open[s]=true;
        while(open[cards[s]]==false)
        {
            open[cards[s]]=true;
            cnt++;
            s=cards[s];
        }
    }

    return cnt;
}

int solution(vector<int> cards) {
    int answer = 0;
    for(int i=0; i<cards.size(); ++i)   cards[i]--;
    vector<bool> open(cards.size(),false);
    bool fin = false;
    vector<int> g;
    while(not fin)  g.push_back(box(open,cards,fin));
    sort(g.begin(),g.end());

    answer = g[g.size()-2]*g[g.size()-1];
    
    return answer;
}