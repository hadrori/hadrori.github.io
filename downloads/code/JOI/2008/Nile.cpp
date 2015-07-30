#include <bits/stdc++.h>
using namespace std;
const int g[] = {10,9,7};
int n, d, f[512][4096], dp[512][4096][4];

int solve()
{

        int m = 0, zero;
        for (int i = 0; i < d; i++) {
                zero = m;
                m = 1e9;
                for (int j = 0; j < n; j++){
                        dp[i+1][j][1] = zero+f[i][j];
                        m = min(m, dp[i+1][j][1]);
                        for (int k = 1; k < 3; k++) {
                                if(!dp[i][j][k]) continue;
                                int nk = min(k+1, 2);
                                if(dp[i+1][j][nk]) dp[i+1][j][nk] = min(dp[i+1][j][nk], dp[i][j][k]+f[i][j]/10*g[k]);
                                else dp[i+1][j][nk] = dp[i][j][k]+f[i][j]/10*g[k];
                                m = min(m, dp[i+1][j][nk]);
                        }
                }
        }

        return m;
}

void input()
{
        cin >> n >> d;
        for (int i = 0; i < d; i++)
                for (int j = 0; j < n; j++)
                        cin >> f[i][j];
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
