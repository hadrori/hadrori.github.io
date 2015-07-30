#include <bits/stdc++.h>
using namespace std;

int n, m, b[16], p[16], cnt[2], cnt2[2];

int calc(int s)
{
        int r[16] = {}, cur = 0;
        for (int i = 0; i < m; i++) {
                for (int j = 0; j < p[i]; j++)
                        r[cur++] = s;
                s ^= 1;
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
                if(r[i] == b[i]) continue;
                for (int j = i+1; j < n; j++) {
                        if(r[j] == b[i]) {
                                ret += j-i;
                                r[j] = r[i];
                                break;
                        }
                }
        }
        return ret;
}

int solve()
{
        for (int i = 0; i < n; i++) cnt[b[i]]++;
        for (int i = 0; i < m; i++) cnt2[i%2] += p[i];
        if(cnt[0] == cnt[1]) return min(calc(0), calc(1));
        if(cnt[0] == cnt2[0]) return calc(0);
        return calc(1);
}

void input()
{
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < m; i++) cin >> p[i];
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
