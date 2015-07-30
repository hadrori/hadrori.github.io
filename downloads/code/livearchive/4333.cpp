#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

int m, nxt[16], prv[16];
i64 dp[1<<16];

bool check(int s)
{
        for (int i = 0; i < m; i++)
                if((s>>i&1) and (s&nxt[i]) != nxt[i]) return 0;
        return 1;
}

i64 solve()
{
        dp[0] = 1;
        for (int s = 0; s < (1<<m); s++) {
                int pc = __builtin_popcount(s);
                if(pc == m/2 and !check(s)) dp[s] = 0;
                for (int i = 0; i < m; i++)
                        if((~s>>i&1) and (s&prv[i]) == prv[i]) dp[1<<i|s] += dp[s];
        }
        return dp[(1<<m)-1];
}

void init()
{
        memset(nxt,0,sizeof(nxt));
        memset(prv,0,sizeof(prv));
        memset(dp,0,sizeof(dp));
}

void input()
{
        init();
        scanf("%d", &m);
        m *= 2;
        char s[32];
        for (int i = 0; i < m; i++) {
                scanf("%s", s);
                for (int j = 0; j < m; j++) {
                        if(s[j] == 'Y') {
                                nxt[i] |= 1<<j;
                                prv[j] |= 1<<i;
                        }
                }
        }
}

int main()
{
        int T; scanf("%d", &T);
        while(T--) {
                input();
                cout << solve() << endl;
        }
        return 0;
}
