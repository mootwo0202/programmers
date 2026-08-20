#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
//길이 10억,숫자 1000만
vector<int> solution(long long begin, long long end) {
    int len=end-begin;
    vector<int> answer(len+1,1);
    
    for(int i=0; i<=len; ++i)        
    {
        int n=0,p=1,t=2;
        while(n==0)
        {
            if(((begin+i)%t==0)&&((begin+i)/t<=10000000))  n=(begin+i)/t;
            else if((begin+i)%t==0) p=t;
            
            if(t>sqrt((begin+i)))  n=p;
            t++;
        }
        answer[i]=n;
    }
    if(begin==1)    answer[0]=0;
        
    return answer;
}