#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;

int w, h, a, b, f[1024][1024], g[1024][1024];

int solve()
{
        for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                        if(f[i][j]<0) f[i][j] = inf;
                        g[i][j] += f[i][j];
                        g[i][min(w,j+a)] -= f[i][j];
                        g[min(h,i+b)][j] -= f[i][j]; 
                        g[min(h,i+b)][min(w,j+a)] += f[i][j]; 
                }
        }
        for (int i = 0; i < h; i++)
                for (int j = 1; j < w; j++)
                        g[i][j] += g[i][j-1];

        for (int i = 1; i < h; i++)
                for (int j = 0; j < w; j++)
                        g[i][j] += g[i-1][j];

        int ans = inf;
        for (int i = b-1; i < h; i++)
                for (int j = a-1; j < w; j++)
                        ans = min(ans, g[i][j]);
        return ans;
}

void input()
{
        cin >> w >> h >> a >> b;
        for (int i = 0; i < h; i++)
                for (int j = 0; j < w; j++)
                        cin >> f[i][j];
}

signed main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
