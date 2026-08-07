#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int n = friends.size();
    vector<vector<int>> g_board(n,vector<int>(n,0));
    for(int i=0; i<gifts.size(); ++i)   
    {
        int pos = gifts[i].find(" ");
        string a = gifts[i].substr(0,pos);
        string b = gifts[i].substr(pos+1);
        
        auto x = find(friends.begin(), friends.end(), a);
        auto y = find(friends.begin(), friends.end(), b);
        int q = x-friends.begin();
        int w = y-friends.begin();
        
        g_board[q][w]++;
    }
    
    vector<int> gift_index(n);
    vector<int> n_gifts(n);
    
    for(int j=0; j<n; ++j)
    {
        int g =0;
        int t = 0;
        for(int k=0; k<n; ++k)
        {
            g += g_board[j][k];
            t += g_board[k][j];
        }
        gift_index[j] = g-t;
    }
    
    for(int l=0; l<n-1; ++l)
    {
        for(int m=l+1; m<n; ++m)
        {
            if(g_board[l][m]>g_board[m][l]) n_gifts[l]++;
            else if(g_board[l][m]<g_board[m][l]) n_gifts[m]++;
            else if((g_board[l][m]==g_board[m][l])&&
                    (gift_index[l]>gift_index[m]))  n_gifts[l]++;
            else if((g_board[l][m]==g_board[m][l])&&
                    (gift_index[l]<gift_index[m]))  n_gifts[m]++;
        }
    }
    sort(n_gifts.begin(), n_gifts.end());
    answer = n_gifts[n-1];
    
    return answer;
}