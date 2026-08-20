#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i=0; i<new_id.size(); ++i)
    {
        if((new_id[i]>='A')&&(new_id[i]<='Z'))  
            answer.push_back(tolower(new_id[i]));
        else if (((new_id[i]>='a')&&(new_id[i]<='z'))||(new_id[i]=='-')||
           (new_id[i]=='_')||(new_id[i]=='.')||
          ((new_id[i]>='0')&&(new_id[i]<='9')))   answer.push_back(new_id[i]);
    }
    
    for(int j=0; j<answer.size(); ++j)
    {
        int l=0;
        if(answer[j]=='.')
        {
            l++;
            while(answer[j+l]=='.'){l++;}
        }
        if(l>1)
        {
            answer.erase(j,l-1);
        }
    }
    
    if(answer[0]=='.')  answer.erase(0,1);
    if(answer[answer.size()-1]=='.')  
        answer.erase(answer.size()-1,1);
    
    if(answer.size()==0)  answer.push_back('a');
    if(answer.size()>=16)
    {
        answer=answer.substr(0,15);
        if(answer[answer.size()-1]=='.')  
            answer.erase(answer.size()-1,1);
    }
    if(answer.size()==1)
    {
        answer.push_back(answer[0]);
        answer.push_back(answer[0]);
    }
    else if(answer.size()==2)   answer+=answer[1];
    
    return answer;
}