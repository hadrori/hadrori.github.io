#include <algorithm>
#include <cstdio>

using namespace std;

int T, W, ans;
int apple[1024];
int dp[1024][32][2];

int main(){
    scanf("%d%d", &T, &W);
    
    for(int i = 0; i < T; i++)
        scanf("%d", apple+i);
    
    if(apple[0] == 1) dp[0][0][0] = 1;
    else dp[0][1][1] = 1;
    for(int i = 0; i < T-1; i++)
        for(int j = 0; j <= W; j++)
            for(int k = 0; k < 2; k++)
                if(k == apple[i+1]-1){
                    dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]+1);
                    dp[i+1][j+1][(k+1)%2] = max(dp[i+1][j+1][(k+1)%2], dp[i][j][k]);
                }
                else {
                    dp[i+1][j+1][(k+1)%2] = max(dp[i+1][j+1][(k+1)%2], dp[i][j][k]+1);
                    dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                }
    
    for(int i = 0; i <= W; i++)
        for(int j = 0; j < 2; j++)
            ans = max(ans, dp[T-1][i][j]);
    printf("%d\n", ans);
    return 0;
}
