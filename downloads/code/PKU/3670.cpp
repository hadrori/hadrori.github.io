#include <algorithm>
#include <cstdio>

using namespace std;

int N;
int num[30010];
int dp[30010][3];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", num+i);
        num[i]--;
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < 3; j++){
            dp[i+1][j] = int(1e9);
            for(int k = 0; k <= j; k++)
                dp[i+1][j] = min(dp[i+1][j], dp[i][k] + int(j!=num[i]));
        }

    int ans = min(dp[N][0],min(dp[N][1],dp[N][2]));
    
    for(int i = 0; i < 3; i++) dp[0][i] = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 3; j++){
            dp[i+1][j] = int(1e9);
            for(int k = j; k < 3; k++)
                dp[i+1][j] = min(dp[i+1][j], dp[i][k] + int(j!=num[i]));
        }
    ans = min(ans, min(dp[N][0],min(dp[N][1],dp[N][2])));
    printf("%d\n", ans);
    return 0;
}
