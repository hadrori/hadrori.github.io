#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int inf = int(1e9);
int N, E, D;
int dp[32][128][128];

int main(){
    scanf("%d%d%d", &N, &E, &D);

    for(int i = 0; i < N; i++)
        for(int j = 0; j <= E; j++)
            for(int k = 0; k <= D; k++)
                dp[i][j][k] = inf;
    dp[0][0][0] = 0;
    int ans = inf;
    for(int i = 0; i < N; i++)
        for(int j = 0; j <=f E; j++){
            for(int k = 0; k < D; k++)
                for(int x = 1; k+x <= D; x++){
                    if(i < N-1 and k+x*x <= E) dp[i+1][k+x*x][k+x] = min(dp[i+1][k+x*x][k+x], dp[i][j][k]+1);
                    if(j+x*x <= E) dp[i][j+x*x][k+x] = min(dp[i][j+x*x][k+x], dp[i][j][k]+1);
                }
            ans = min(ans, dp[i][j][D]);
        }
    if(ans == inf) ans = 0;
    printf("%d\n", ans);
    return 0;
}
