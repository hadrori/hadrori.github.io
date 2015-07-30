#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<int> E[5010];
vector<int> RE[5010];
int dp[5010];
int dp2[5010];

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        int a, b; scanf("%d%d", &a, &b);
        a--; b--;
        E[a].push_back(b);
        RE[b].push_back(a);
    }

    int ans = 0;
    dp[N-1] = 1;
    for(int i = N-1; i >= 0; i--)
        for(int j = 0; j < RE[i].size(); j++)
            dp[RE[i][j]] += dp[i];

    for(int i = 0; i < N; i++){
        if(!dp2[i]) dp2[i] = 1;
        for(int j = 0; j < E[i].size(); j++){
            dp2[E[i][j]] += dp2[i];
            ans = max(ans, dp2[i] * dp[E[i][j]]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
