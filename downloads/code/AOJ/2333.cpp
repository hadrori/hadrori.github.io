#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
const int mod = 1e9+7;
int N, W, w[256];
int dp[10010], sum[256];
inline void f(int &a, int b){ a=(a+b)%mod;}
 
int solve(){
    sort(w,w+N);
    rep(i,N) sum[i+1] = sum[i] + w[i];
    int ans = sum[N]==W;
    rep(i,N){
        memset(dp, 0, sizeof(dp));
        if(sum[i] > W) break;
        dp[sum[i]] += 1;
        repi(j,i+1,N) for(int k = W; k-w[j]>=sum[i]; k--)
            f(dp[k], dp[k-w[j]]);
        repi(j,W-w[i]+1,W+1) f(ans, dp[j]);
    }
    return ans;
}
 
 
int main(){
    cin >> N >> W;
    rep(i,N) cin >> w[i];
    cout << solve() << endl;
    return 0;
}