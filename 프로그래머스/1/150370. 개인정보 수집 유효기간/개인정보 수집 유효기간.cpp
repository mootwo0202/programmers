#include <string>
#include <vector>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int tod = 10000*stoi(today.substr(0,4))+100*stoi(today.substr(5,2))+
        stoi(today.substr(8,2));
    for(int i=0; i<privacies.size(); ++i)
    {
        int ind=0;
        for(int j=0; j<terms.size(); ++j)
        {
            if(terms[j][0]==privacies[i][11])   ind=j;
        }
        int ter=stoi(terms[ind].substr(2));
        int y=ter/12;
        int m=ter%12;
        int pri_m=stoi(privacies[i].substr(5,2));
        if(pri_m+m>12)
        {
            y++;
            m-=12;
        }
        int st = 10000*stoi(privacies[i].substr(0,4))+
            100*stoi(privacies[i].substr(5,2))+stoi(privacies[i].substr(8,2));
        int max=st+y*10000+m*100;
        if(max<=tod)  answer.push_back(i+1);
        
    }
    
    
    return answer;
}