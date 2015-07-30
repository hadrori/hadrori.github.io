#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int N, B;
int util[4096];
int dp[2][4096][4];

void calc(){
    for(int i = 0; i < N; i++){
        int s = i%2, t = (i+1)%2;
        memset(dp[t], -1, sizeof(dp[t]));
        for(int j = 0; j <= B; j++){
            for(int k = 0; k < 3; k++){
                dp[t][j][0] = max(dp[t][j][0], dp[s][j][k]);
                if(j < B and dp[s][j][k] >= 0)
                    dp[t][j+1][1+(k>0)] = max(dp[t][j+1][1+(k>0)], dp[s][j][k] + (k>0)*util[i]);
            }
        }
    }
}

int main(){
    scanf("%d%d", &N, &B);
    for(int i = 0; i < N; i++)
        scanf("%d", util+i);
    int ans = 0;
    for(int i = 0; i < 2; i++){
        memset(dp, -1, sizeof(dp));
        dp[0][0][i*2] = 0;
        calc();
        for(int k = i; k < 3; k++)
            ans = max(ans, dp[N%2][B][k]);
    }
    printf("%d\n", ans);
    return 0;
}
