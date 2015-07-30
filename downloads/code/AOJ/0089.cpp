#include <iostream>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int main(){
    int w;
    int i = 0, j = 0;
    int g[128][128];
    while(cin >> w){
        g[i][j++] = w;
        char c = cin.get();
        if(c == '\n'){
            i++;
            j = 0;
        }
    }
    int dp[128][128] = {0};
    dp[0][0] = g[0][0];
    repi(a,1,i+1)rep(b,a+1){
        if(a < i/2 + 1){
            if(!b) dp[a][b] = dp[a-1][b] + g[a][b];
            else if(b == a) dp[a][b] = dp[a-1][b-1] + g[a][b];
            else dp[a][b] = max(dp[a-1][b],dp[a-1][b-1]) + g[a][b];
        }else{
            dp[a][b] = max(dp[a-1][b],dp[a-1][b+1]) + g[a][b];
        }
    }
    cout << dp[i][0] << endl;
}
