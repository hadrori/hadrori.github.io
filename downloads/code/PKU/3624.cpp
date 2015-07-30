#include <algorithm>
#include <cstdio>

using namespace std;

int N, M;
int dp[13000];
int p[3410], w[3410];

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d%d", w+i, p+i);
    for(int i = 0; i < N; i++)
        for(int j = M - w[i]; j >= 0; j--)
            dp[j+w[i]] = max(dp[j+w[i]], dp[j]+p[i]);
    int ans = 0;
    for(int i = 0; i <= M; i++)
        ans = max(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}
