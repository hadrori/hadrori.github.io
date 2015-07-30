#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 1000000;

int T, A, S, B;
int family[1024];
int sum[1024];
int dp[2][100010];

int main(){
    scanf("%d%d%d%d", &T, &A, &S, &B);
    for(int i = 0; i < A; i++){
        int f; scanf("%d", &f);
        family[f]++;
    }

    for(int i = 1; i <= T; i++)
        sum[i] = sum[i-1] + family[i];

    dp[0][0] = 1;
    for(int i = 1; i <= T; i++){
        int cur = i % 2;
        memset(dp[cur], 0, sizeof(dp[cur]));
        for(int k = 0; k <= family[i]; k++)
            for(int j = sum[i]; j >= k; j--)
                dp[cur][j] = (dp[cur][j] + dp[(cur+1)%2][j-k]) % mod;
    }
    int ans = 0;
    for(int i = S; i <= B; i++)
        ans = (ans + dp[T%2][i]) % mod;

    printf("%d\n", ans);
    return 0;
}
