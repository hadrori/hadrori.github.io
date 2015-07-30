#include <algorithm>
#include <cstdio>

using namespace std;

typedef pair<int,int> pii;

const int base = 100000;
int N, S[128], F[128];
int left, right;
int dp[128][200010];

int main(){
    scanf("%d", &N);
    left = right = 0;
    for(int i = 0; i < N; i++)
        scanf("%d%d", S+i, F+i);

    dp[0][base] = base;
    left = right = base;
    for(int i = 0; i < N; i++){
        int tl = left, tr = right;
        for(int j = left; j <= right; j++)
            if(dp[i][j]){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                dp[i+1][j+S[i]] = max(dp[i+1][j+S[i]], dp[i][j] + F[i]);
                tl = min(tl, j+S[i]);
                tr = max(tr, j+S[i]);
            }
        left = tl;
        right = tr;
    }
    
    int ans = 0;
    for(int i = base; i <= right; i++)
        if(dp[N][i] >= base) ans = max(ans, i + dp[N][i] - 2*base);
    printf("%d\n", ans);
    return 0;
}
