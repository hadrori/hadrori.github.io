#include <bits/stdc++.h>
using namespace std;
const double inf = 1e9;

struct edge
{
        int to, d, s;
};

int n, m, c, a[10010];
double dp[10010];
vector<edge> G[10010];

inline void chmin(double &a, double b){a=min(a,b);}

bool ok(double x)
{
        fill(dp,dp+n,inf);
        for (int i = 0; i < m; i++) dp[a[i]] = 0;
        for (int i = 0; i < n-1; i++)
                for(auto &e: G[i])
                        chmin(dp[e.to],dp[i]+e.d-x*e.d/e.s);
        return dp[n-1] <= 0;
}

int solve()
{
        double lb = 0, ub = inf, mid;
        for (int _ = 0; _ < 100; _++) {
                mid = (lb+ub)/2;
                if(ok(mid)) ub = mid;
                else lb = mid;
        }
        return ub+0.5;
}

void input()
{
        cin >> n >> m >> c;
        for (int i = 0; i < m; i++) {
                cin >> a[i];
                a[i]--;
        }
        int f, t, d, s;
        for (int i = 0; i < c; i++) {
                cin >> f >> t >> d >> s;
                f--; t--;
                G[f].push_back((edge){t,d,s});
        }
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
