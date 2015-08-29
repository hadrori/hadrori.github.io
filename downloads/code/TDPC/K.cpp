#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

const int inf = 1e9;
int n, dp[100010];
pair<int,int> cs[100010];


int solve() {
    sort(cs, cs+n);
    rep(i,n) dp[i] = inf;
    for(int i = n-1; i >= 0; i--)
        dp[lower_bound(dp,dp+n,cs[i].second)-dp] = cs[i].second;
    return lower_bound(dp,dp+n,inf)-dp;
}

void input() {
    scanf("%d", &n);
    rep(i,n) {
        int x, y; scanf("%d%d", &x, &y);
        cs[i].first = x-y;
        cs[i].second = x+y;
    }
}

int main() {
    input();
    printf("%d\n", solve());
    return 0;
}
