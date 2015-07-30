#include <bits/stdc++.h>
using namespace std;

int n, h, w;
map<pair<int,int>, int> f;

void solve()
{
        
        int p, q, r, s, m = 0, area = 0;
        for (int i = 0; i < n; i++) {
                cin >> p >> q >> r >> s;
                p--; q--;
                for (int y = q; y < s; y++) {
                        for (int x = p; x < r; x++) {
                                int t = ++f[pair<int,int>(x,y)];
                                if(t > m) {
                                        m = t;
                                        area = 0;
                                }
                                if(t == m) area++;
                        }
                }
        }
        cout << m << endl;
        cout << area << endl;
}

void input()
{
        cin >> n >> w >> h;
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
