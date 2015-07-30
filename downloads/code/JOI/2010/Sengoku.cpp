#include <bits/stdc++.h>
using namespace std;
#define int long long

int l, n;
vector<int> p[2], m[2];

int solve()
{
        for (int i = 0; i < 2; i++) {
                sort(begin(p[i]),end(p[i]));
                p[i].erase(unique(begin(p[i]),end(p[i])),end(p[i]));
                sort(begin(m[i]),end(m[i]));
                m[i].erase(unique(begin(m[i]),end(m[i])),end(m[i]));
        }

        int ans = 0;
        for (int i = 0; i < 2; i++) {
                for(auto &e: p[i]) {
                        int b = abs(e);
                        ans += l-b;
                        ans -= upper_bound(begin(m[i]),end(m[i]),2*(l-1)-b)-lower_bound(begin(m[i]),end(m[i]),b);
                }
                for(auto &e: m[i]) ans += l-abs(l-1-e);
                
        }
        return ans;
}

void input()
{
        cin >> l >> n;
        for (int i = 0; i < n; i++) {
                int x, y;
                cin >> x >> y;
                p[(y-x)&1].push_back(y-x);
                m[(y+x)&1].push_back(y+x);
        }
}

signed main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
