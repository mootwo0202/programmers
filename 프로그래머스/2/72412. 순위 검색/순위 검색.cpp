#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

void find(unordered_map<int,int>& in,vector<map<int,int>>& score,
          string q,vector<int>& answer,int k){
    int value=0,j=0;
    vector <int> key;
    //개발언어
    if(q[j]=='c')
    {
        key.push_back(1000);
        j+=8;
    }
    else if(q[j]=='j')
    {
        key.push_back(2000);
        j+=9;
    }
    else if(q[j]=='p')
    {
        key.push_back(3000);
        j+=11;
    }
    else if(q[j]=='-')
    {
        key.push_back(1000);
        key.push_back(2000);
        key.push_back(3000);
        j+=6;
    }
    //지원직군
    if(q[j]=='b')
    {
        for(int i=0;i<key.size();++i)   key[i]+=100;
        j+=12;
    }
    else if(q[j]=='f')
    {
        for(int i=0;i<key.size();++i)   key[i]+=200;
        j+=13;
    }
    else if(q[j]=='-')
    {
        vector <int> x = key;
        for(int i=0;i<key.size();++i)   key[i]+=100;
        for(int h=0;h<key.size();++h)   x[h]+=200;
        key.insert(key.end(),x.begin(),x.end());
        j+=6;
    }
    //경력
    if(q[j]=='j')
    {
        for(int i=0;i<key.size();++i)   key[i]+=10;
        j+=11;
    }
    else if(q[j]=='s')
    {
        for(int i=0;i<key.size();++i)   key[i]+=20;
        j+=11;
    }
    else if(q[j]=='-')
    {
        vector <int> y = key;
        for(int i=0;i<key.size();++i)   key[i]+=10;
        for(int h=0;h<key.size();++h)   y[h]+=20;
        key.insert(key.end(),y.begin(),y.end());
        j+=6;
    }
    //소울푸드
    if(q[j]=='c')
    {
        for(int i=0;i<key.size();++i)   key[i]+=1;
        j+=8;
    }
    else if(q[j]=='p')
    {
        for(int i=0;i<key.size();++i)   key[i]+=2;
        j+=6;
    }
    else if(q[j]=='-')
    {
        vector <int> z = key;
        for(int i=0;i<key.size();++i)   key[i]+=1;
        for(int h=0;h<key.size();++h)   z[h]+=2;
        key.insert(key.end(),z.begin(),z.end());
        j+=2;
    }
    
    //점수
    string s=q.substr(j);
    value=stoi(s);
    
    //결론
    for(int g=0; g<key.size(); ++g)
    {
        auto it = in.find(key[g]);
        if(it==in.end())        continue;
        auto ir = score[it->second].lower_bound(value);
        if(ir != score[it->second].end())   answer[k]+=ir->second;
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(),0);
    unordered_map<int,int> in;
    vector<map<int,int>> score;
    int num=0;
    for(int i=0; i<info.size(); ++i)
    {
        int st=0,cnt=-1;
        int key=0,value=0,j=0;
        //개발언어
        if(info[i][j]=='c')
        {
            key+=1000;
            j+=4;
        }
        else if(info[i][j]=='j')
        {
            key+=2000;
            j+=5;
        }
        else if(info[i][j]=='p')
        {
            key+=3000;
            j+=7;
        }
        //지원직군
        if(info[i][j]=='b')
        {
            key+=100;
            j+=8;
        }
        else if(info[i][j]=='f')
        {
            key+=200;
            j+=9;
        }
        //경력
        if(info[i][j]=='j')
        {
            key+=10;
            j+=7;
        }
        else if(info[i][j]=='s')
        {
            key+=20;
            j+=7;
        }
        //소울푸드
        if(info[i][j]=='c')
        {
            key+=1;
            j+=7;
        }
        else if(info[i][j]=='p')
        {
            key+=2;
            j+=6;
        }
        //점수
        string x=info[i].substr(j);
        value=stoi(x);
        
        auto it=in.find(key);
        if(it==in.end())
        {
            in.insert({key,num});
            score.push_back(map<int,int>());
            score[num].insert({value,1});
            num++;
        }
        else
        {
            auto ir=score[it->second].find(value);
            if(ir==score[it->second].end())
                score[it->second].insert({value,1});
            else    score[it->second][value]++;
        }
    }
    
    for(int l=0; l<score.size();++l)
    {
        int sum = 0;

        for(auto itr=score[l].rbegin();itr!=score[l].rend();++itr)
        {
            sum += itr->second;
            itr->second = sum;
        }
    }
    
    for(int k=0; k<query.size(); ++k)   find(in,score,query[k],answer,k);
    
    return answer;
}