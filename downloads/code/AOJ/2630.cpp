#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const char base = 'a'-1;

inline int add(int &x, int y) { return x=(x+y)%mod;}
inline int mul(int x, int y) { return 1LL*x*y%mod;}

int n, dp[64][64][32][32];
char s[64][32];

int solve(int l, int r, int a, int b)
{
        int &ret = dp[l][r][a][b];
        if(~ret) return ret;
        if(l >= r) return ret = 1;

        ret = 0;
        if(b == 27) return ret;
        if(a == 20) return ret = r-l==1;

        for (int i = l; i <= r; i++) {
                if(i != l and ((s[i-1][a] != base+b and s[i-1][a] != '?') or
                               (s[i-1][a] == '?' and b == 0))) break;
                add(ret, mul(solve(l,i,a+1,0), solve(i,r,a,b+1)));
        }
        return ret;
}

void input()
{
        memset(dp,-1,sizeof(dp));
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                scanf("%s", s[i]);
                for (int j = strlen(s[i]); j < 20; j++) s[i][j] = base;
        }
}

int main()
{
        input();
        printf("%d\n", solve(0,n,0,0));
        return 0;
}
