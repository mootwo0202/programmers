#include <iostream>
#include <string>
#include <vector>

using namespace std;

void command(string cmd,vector<int> &po,vector<int> vid_len,vector<int> op_st,vector<int> op_en){
    if(cmd=="next")
    {
        if(po[1]<50)  po[1]+=10;
        else
        {
            po[0]++;
            po[1]-=50;
        }
    }
    if(cmd=="prev")
    {
        if(po[1]>=10)  po[1]-=10;
        else
        {
            po[0]--;
            po[1]+=50;
        }
    }
    if((po[0]>vid_len[0])||(po[0]==vid_len[0]&&po[1]>vid_len[1]))   po = vid_len;
    if((po[0]<0)||(po[0]==0&&po[1]<0))  po = {0,0};
    if(((po[0]>op_st[0])||(po[0]==op_st[0]&&po[1]>=op_st[1]))
       &&((po[0]<op_en[0])||(po[0]==op_en[0]&&po[1]<op_en[1])))  po = op_en;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    vector<int> vid_len{stoi(video_len.substr(0,2)),stoi(video_len.substr(3))};
    vector<int> po{stoi(pos.substr(0,2)),stoi(pos.substr(3))};
    vector<int> op_st{stoi(op_start.substr(0,2)),stoi(op_start.substr(3))};
    vector<int> op_en{stoi(op_end.substr(0,2)),stoi(op_end.substr(3))};
    
    if((po[0]>vid_len[0])||(po[0]==vid_len[0]&&po[1]>vid_len[1]))   po = vid_len;
    if(((po[0]>op_st[0])||(po[0]==op_st[0]&&po[1]>=op_st[1]))
       &&((po[0]<op_en[0])||(po[0]==op_en[0]&&po[1]<op_en[1])))  po = op_en;
    
    
    
    for(int i=0; i<commands.size(); ++i)
    {
        command(commands[i],po,vid_len,op_st,op_en);
    }
    string min = to_string(po[0]);
    if(min.size()<2)  min = '0'+min;
    string sec = to_string(po[1]);
    if(sec.size()<2)  sec = '0'+sec;
    answer = min+":"+sec;
    
    
    return answer;
}