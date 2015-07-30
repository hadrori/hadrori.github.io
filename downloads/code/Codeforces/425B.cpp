#include <bits/stdc++.h>
using namespace std;

int n, m, k, a[128][128];

inline int ith(int bit, int i){ return ((bit>>i)&1);}

int solve_s()
{
        int ret = k+1;
        for (int y = 0; y < 1<<n; y++) {
                int tmp = 0;
                for (int j = 0; j < m; j++) {
                        int cnt = 0;
                        for (int i = 0; i < n; i++)
                                cnt += a[i][j]^kth(y,i);
                        tmp += min(cnt, n-cnt);
                }
                ret = min(ret, tmp);
        }
        return ret;
}

int solve_l()
{
        int ret = k+1;
        for (int ii = 0; ii < n; ii++) {
                int tmp = 0;
                for (int i = 0; i < n; i++) {
                        if(i == ii) continue;
                        int cnt = 0;
                        for (int j = 0; j < m; j++)
                                cnt += a[i][j]^a[ii][j];
                        tmp += min(cnt, m-cnt);
                }
                ret = min(ret, tmp);
        }

        return ret;
}

int solve()
{
        int ans;
        if(n <= k) ans = solve_s();
        else ans = solve_l();
        return ans>k? -1: ans;
}

void input()
{
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                        cin >> a[i][j];
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
