#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int n, h[1024], dp[1024];

int solve()
{
        for (int i = 0; i < n; i++) dp[i] = inf;
        for (int i = 0; i < n; i++) *lower_bound(dp,dp+n,h[i]) = h[i];
        return lower_bound(dp,dp+n,inf)-dp;
}

void input()
{
        cin >> n;
        for (int i = 0; i < n; i++) cin >> h[i];
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
