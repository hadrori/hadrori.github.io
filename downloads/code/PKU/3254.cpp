#include <cstdio>

using namespace std;

const int mod = 100000000;
int M, N;
int field[16][16];
int dp[16][1<<13];

inline bool valid(int i, int S){
    int prev = 0;
    for(int j = 0; j < N; j++){
        if(S&(1<<j)) {
            if(prev or !field[i][j]) return 0;
            prev = 1;
        }
        else prev = 0;
    }
    return 1;
}

int main(){
    scanf("%d%d", &M, &N);
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &field[i][j]);
    
    dp[0][0] = 1;
    for(int i = 1; i <= M; i++)
        for(int S = 0; S < (1<<N); S++)
            if(valid(i-1,S))
                for(int T = 0; T < (1<<N); T++)
                    if(!(S&T)) dp[i][S] = (dp[i][S]+dp[i-1][T])%mod;

    int ans = 0;
    for(int i = 0; i < (1<<N); i++)
        ans = (ans+dp[M][i])%mod;
    printf("%d\n", ans);
    return 0;
}
