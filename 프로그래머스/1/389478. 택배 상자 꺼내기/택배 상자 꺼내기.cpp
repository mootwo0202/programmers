#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    //0층부터 시작
    int h_tar = num/w;
    if(num%w==0)    h_tar--;
    
    int h_max = n/w;
    if(n%w==0)    h_max--;
    
    //왼쪽부터 1부터 시작
    //짝수층
    int p_tar = 0;
    if(h_tar%2==0)
    {
        p_tar = num%w;
        if(num%w==0)    p_tar = w;
    }
    //홀수층
    else if(h_tar%2==1)
    {
        p_tar = w-(num%w)+1;
        if(num%w==0)    p_tar = 1;
    }
    
    //짝수층
    int p_max = 0;
    if(h_max%2==0)
    {
        p_max = n%w;
        if(n%w==0)    p_max = w;
        
        if(p_max>=p_tar)    answer=h_max-h_tar+1;
        else    answer=h_max-h_tar;
    }
    //홀수층
    else if(h_max%2==1)
    {
        p_max = w-(n%w)+1;
        if(n%w==0)    p_max = 1;
        
        if(p_max<=p_tar)    answer=h_max-h_tar+1;
        else    answer=h_max-h_tar;
    }
    
    
    
    return answer;
}