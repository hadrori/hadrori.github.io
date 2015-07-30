#include <algorithm>
#include <cstdio>

using namespace std;

int N, M;
int D[10010];
int dp[10010][512];

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", D+i);

    dp[0][0] = 0;
    for(int i = 0; i < N; i++){
        dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
        for(int j = 0; j <= min(i, M); j++){
            if(j < M) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + D[i]);
            if(i+j <= N)dp[i+j][0] = max(dp[i+j][0], dp[i][j]);
        }
    }

    printf("%d\n", dp[N][0]);
    return 0;
}
