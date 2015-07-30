#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9+7;
 
int n, x, dp[2048][2048], inv[2048];
long long d;
 
int solve()
{
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                        dp[i+1][j+1] = (dp[i+1][j]+dp[i][j])%mod;
                        if(j+1 >= x) dp[i+1][j+1] = (dp[i+1][j+1]-dp[i][j-x+1]+mod)%mod;
                }
        }
 
        int ans = 0;
        for (int i = 1; i <= min(1LL*n, d); i++) {
                int tmp = dp[i][n];
                for (int j = 0; j < i; j++) {
                        tmp = 1LL*(d-j)%mod*tmp%mod;
                        tmp = 1LL*tmp*inv[i-j]%mod;
                }
                ans = (ans+tmp)%mod;
        }
        return ans;
}
 
bool input()
{
        scanf("%d%lld%d", &n, &d, &x);
        return n or d or x;
}
 
int main()
{
        inv[1] = 1;
        for(int i = 2; i < 2048; ++i) inv[i] = 1LL*inv[mod%i]*(mod-mod/i)%mod;
         
        while(input()) printf("%d\n", solve());
        return 0;
}