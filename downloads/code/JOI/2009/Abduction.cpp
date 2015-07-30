#include <bits/stdc++.h>
using namespace std;
const int mod = 1e7;
const int r[4] = {3,2,0,1}, l[4] = {2,3,1,0}, pm[2] = {-1,1};
inline void add(int &a, int b){a=(a+b)%mod;}
inline void mul(int &a, int b){a=1LL*a*b%mod;}
 
int wh[2], n, dp[1010];
string s;
vector<int> d[2];
 
int solve()
{
        int dir = ((s[0]=='R')<<1)|1;
        d[dir>>1].push_back(pm[dir&1]);
        for(auto &c: s) {
                if(c=='R') dir = r[dir];
                else dir = l[dir];
                d[dir>>1].push_back(pm[dir&1]);
        }
        int ans = 1;
        for (int k = 0; k < 2; k++) {
                memset(dp,0,sizeof(dp));
                dp[0] = 1;
                for(auto &p: d[k]) {
                        if(p<0) {
                                for (int i = wh[k]-1; i >= 0; i--) add(dp[i],dp[i+1]);
                                for (int i = 0; i < wh[k]; i++) dp[i] = dp[i+1];
                                dp[wh[k]] = 0;
                        }
                        else {
                                for (int i = 1; i <= wh[k]; i++) add(dp[i],dp[i-1]);
                                for (int i = wh[k]; i > 0; i--) dp[i] = dp[i-1];
                                dp[0] = 0;
                        }
                }
                mul(ans, dp[wh[k]]);
        }
 
        return ans;
}
 
void input()
{
        cin >> wh[0] >> wh[1] >> n;
        cin >> s;
}
 
int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
