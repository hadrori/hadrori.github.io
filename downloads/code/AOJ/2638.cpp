#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int mod = 1e9+7;

inline void add(i64 &x, i64 y) { x = (x+y+mod)%mod;}
inline i64 mul(i64 x, i64 y) { return x*y%mod;}

i64 d, s, l[512], dp[2][100010];

i64 solve()
{
        dp[0][0] = 1;
        for (int i = 0; i < d; i++) {
                const int ni = (i+1)%2;
                memset(dp[ni],0,sizeof(dp[ni])); 
                for (int j = 0; j < d*301; j++) {
                        add(dp[ni][j], dp[i%2][j]);
                        add(dp[ni][j+l[i]], -dp[i%2][j]);
                }
        }

        i64 ans = 0;
        for (int i = 0; i < s; i++) {
                i64 res = 1;
                for (int j = 0; j < d; j++) res = mul(res, s-i);
                add(ans, mul(dp[d%2][i], res));
        }
        return ans;
}

void input()
{
        scanf("%lld", &d);
        for (int i = 0; i < d; i++) scanf("%lld", l+i);
        scanf("%lld", &s);
}

int main()
{
        input();
        printf("%lld\n", solve());
        return 0;
}
