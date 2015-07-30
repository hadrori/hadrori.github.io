#include <iostream>
#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
const int mod = 1000000007;
int N, K;
int dp[1000010]; //cases that not stop station k
int sum[1000010];

void input(){ cin >> N >> K; }

int solve(){
    dp[0] = sum[1] = 1;
    repi(i,1,N+2){
        if(i != 1 && i != N)dp[i] = (sum[i] - sum[max(i-K, 0LL)] + mod) % mod;
        sum[i+1] += dp[i] + sum[i];
        sum[i+1] %= mod;
    }
    return dp[N+1];
}

signed main(){
    input();
    cout << solve() << endl;
    return 0;
}
