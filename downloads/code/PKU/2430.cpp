#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;
int N, K, B, W;
pii cows[1024];
int unzip[1024];
int cow[1024];
int dp[1024][1024][4];
inline void mymin(int &a, int b){
    if(a < 0) a = b;
    a = min(a, b);
}

int main(){
    scanf("%d%d%d",&N,&K,&B);
    vector<int> tmp;
    for(int i = 0; i < N; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        cows[i] = pii(b,a);
        tmp.push_back(b);
    }
    sort(tmp.begin(), tmp.end());
    sort(cows, cows+N);
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    W = tmp.size();
    int cur = 0;
    for(int i = 0; i < W; i++){
        unzip[i+1] = tmp[i];
        while(cur < N and tmp[i] == cows[cur].first){
            cow[i+1] |= (1<<cows[cur++].second);
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for(int i = 0; i < W; i++)
        for(int k = 0; k <= K; k++){
            if(k == 0 and i > 0) continue;
            for(int u = 0; u < 4; u++){
                if(dp[i][k][u] < 0) continue;
                for(int v = 0; v < 4; v++){
                    int cover = v==0? 3: v;
                    int f = __builtin_popcount(cover);
                    if((cover&cow[i+1]) != cow[i+1]) continue;
                    if(k > 0){ // can continue
                        if(v == u or ((v == 1 or v == 2) and u == 3))
                            mymin(dp[i+1][k][v], dp[i][k][u]+f*(unzip[i+1]-unzip[i]));
                        if(v == 3 and k < K and u > 0)
                            mymin(dp[i+1][k+1][v], dp[i][k][u]+unzip[i+1]-unzip[i]+1);
                    }
                    if(k < K and v < 3) mymin(dp[i+1][k+1][v], dp[i][k][u]+f);
                    if(v == 3 and k < K-1) mymin(dp[i+1][k+2][v], dp[i][k][u]+f);
                }
            }
        }

    int ans = 2*B;
    for(int i = 0; i < 4; i++)
        if(dp[W][K][i] >= 0) mymin(ans, dp[W][K][i]);
    printf("%d\n", ans);
    return 0;
}
