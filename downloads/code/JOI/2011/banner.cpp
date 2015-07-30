#include <bits/stdc++.h>
using namespace std;

long long h, w, col[512][512], cnt[8], ans[8];

long long solve()
{
        for (int i = 0; i < h; i++) {
                for (int ii = i+1; ii < h; ii++) {
                        memset(cnt,0,sizeof(cnt));
                        for (int j = 0; j < w; j++) cnt[col[i][j]|col[ii][j]]++;
                        for (int j = 0; j < 8; j++)
                                for (int k = 0; k < 8; k++)
                                        ans[j|k] += cnt[j]*cnt[k];
                }
        }

        return ans[7]/2;
}

void input()
{
        cin >> h >> w;
        int c;
        for (int i = 0; i < h; i++)
                for (int j = 0; j < w; j++) {
                        cin >> c;
                        col[i][j] = 1<<c;
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
