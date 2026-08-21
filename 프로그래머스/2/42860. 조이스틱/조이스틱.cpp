#include <string>
#include <vector>
#include <cmath>

using namespace std;

int cnt(char x){
    int a=x-'A';
    int z='Z'-x+1;
    
    return min(a,z);
}

int solution(string name) {
    int answer = 0;
    if(name.size()==1)  answer=cnt(name[0]);
    else 
    {
        //바꾸기
        for(int i=0; i<name.size(); ++i)    answer+=cnt(name[i]);
        //양방향
        int long_a=0,a_e=0,cc=name.size()-1;
        for(int j=1; j<name.size(); ++j)
        {
            if(name[j]=='A')
            {
                int a_s=j;
                while(j<name.size() && name[j]=='A')
                {
                    j++;
                }
                int a_e=j-1;
                int s_c=(a_s-1)*2 + (name.size()-a_e-1);
                int e_c=(a_s-1) + (name.size()-a_e-1)*2;
                cc=min(cc, min(s_c,e_c));
            }
        }
        
        answer+=cc;
    }
    
    return answer;
}