#include <bits/stdc++.h>
using namespace std;

int n, m, t, x, y;
int wa[1024][16], tim[1024][16], ans[1024], p[16];

void solve()
{
        for (int i = 0; i < y; i++) {
                int s, id, task;
                string v;
                cin >> s >> id >> task >> v;
                id--; task--;
                if(v == "open") tim[id][task] = s;
                else if(v == "correct") ans[id] += max(x, p[task]-(s-tim[id][task])-120*wa[id][task]);
                else wa[id][task]++;
        }
        for (int i = 0; i < n; i++) cout << ans[i] << endl;
}

void input()
{
        cin >> n >> m >> t >> x >> y;
        for (int i = 0; i < m; i++) cin >> p[i];
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
