#include <cstdio>
#include <cstring>

using namespace std;

#define int long long

int N, K;
int dp[128][1024];

signed main(){
    scanf("%lld%lld", &N, &K);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= K; i++)
        for(int k = 0; k <= N; k+=i)
            for(int j = N; j >= k; j--)
                dp[i][j] += dp[i-1][j-k];
    printf("%lld\n", dp[K][N]);
}

