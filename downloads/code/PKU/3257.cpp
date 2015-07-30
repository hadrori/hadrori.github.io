#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct S{ int w, f, c;};

int L, N, B;
vector<S> cmp[1024];
int dp[1024][1024];

int main(){
    scanf("%d%d%d", &L, &N, &B);
    for(int i = 0; i < N; i++){
        int x, w, f, c; scanf("%d%d%d%d", &x, &w, &f, &c);
        cmp[x].push_back((S){w,f,c});
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i < L; i++)
        for(int j = 0; j < B; j++)
            if(dp[i][j] >= 0)
                for(int k = 0; k < cmp[i].size(); k++){
                    int ni = i + cmp[i][k].w, nj = j + cmp[i][k].c;
                    if(nj <= B) dp[ni][nj] = max(dp[ni][nj], dp[i][j]+cmp[i][k].f);
                }
    int ans = -1;
    for(int i = 0; i <= B; i++)
        ans = max(ans, dp[L][i]);
    printf("%d\n", ans);
    return 0;
}
