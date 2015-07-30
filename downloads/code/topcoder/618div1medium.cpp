#define int long long
const int mod = 1e9+7;
int dp[5010];
class LongWordsDiv1 {
public:
    signed count( signed n ) {
        memset(dp, 0, sizeof(dp));
        dp[1] = dp[2] = 1;
        repi(i,3,n+1){
            dp[i] = dp[i-1];
            repi(j,1,i-1)
                dp[i] = (dp[i]+dp[j]*dp[i-j-1]%mod)%mod;
        }
        int ans = dp[n];
        repi(i,1,n+1) ans = (ans*i)%mod;
        return ans;
    }
};
#undef int
