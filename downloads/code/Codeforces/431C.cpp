#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
const int mod = 1e9+7;
inline int f(int &a, int b){ return a=(a+b)%mod;}
int N, K, D, dp[2][128], ndp[2][128], ans;

int solve(){
    dp[0][0] = 1;
    rep(i,N){
        memset(ndp,0,sizeof(ndp));
        repi(j,1,K+1)rep(k,N-j+1){
            if(j < D) f(ndp[0][k+j],dp[0][k]);
            else f(ndp[1][k+j],dp[0][k]);
            f(ndp[1][k+j],dp[1][k]);
        }
        swap(dp,ndp);
        f(ans,dp[1][N]);
    }
    return ans;
}

void input(){
    cin >> N >> K >> D;
}

int main(){
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
