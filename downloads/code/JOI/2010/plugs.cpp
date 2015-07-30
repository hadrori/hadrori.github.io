#include <bits/stdc++.h>
using namespace std;

int n, m, f[3010][3010], res[3010], ans[3010];

void solve()
{
        for (int i = 0; i < n; i++)
                for (int j = 1; j < n; j++)
                        f[i][j] += f[i][j-1];
        for (int i = 1; i < n; i++)
                for (int j = 0; j < n; j++)
                        f[i][j] += f[i-1][j];
        for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                        res[i] += !f[i][j];
        
        for (int _ = 0; _ < n; _++) {
                for (int i = 0; i < n; i++)
                        if(res[i] == 1) {
                                for (int j = 0; j < n; j++)
                                        if(!f[i][j]) {
                                                ans[i] = j;
                                                break;
                                        }
                                for (int j = 0; j < n; j++) {
                                        res[j] -= !f[j][ans[i]];
                                        f[j][ans[i]] = 1;
                                }
                        }
        }
        for (int i = 0; i < n; i++) cout << ans[i]+1 << endl;
}

void input()
{
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
                int a, b, c, d;
                cin >> a >> b >> c >> d;
                a--; c--;
                f[a][c] += 1;
                f[a][d] -= 1;
                f[b][c] -= 1;
                f[b][d] += 1;
        }
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
