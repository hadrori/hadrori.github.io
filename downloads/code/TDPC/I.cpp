#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

char s[512];
int n, dp[512][512];

int solve() {
    repi(d,3,n+1) rep(l,n-d+1) {
        int r = l+d;
        repi(m,l,r) dp[l][r] = max(dp[l][r], dp[l][m]+dp[m][r]);
        if(s[l] != 'i' or s[r-1] != 'i') continue;
        repi(m,l+1,r-1) if(s[m] == 'w' and dp[l+1][m] == m-l-1 and dp[m+1][r-1] == r-m-2)
            dp[l][r] = r-l;
    }
    return dp[0][n]/3;
}

void input() {
    scanf("%s", s);
    n = strlen(s);
}

int main() {
    input();
    printf("%d\n", solve());
    return 0;
}
