#include <bits/stdc++.h>
using namespace std;

int k, n, m, p[1<<17], q[1<<17], res;

void solve()
{
        sort(q, q+k);
        res = 100*(n-m);
        for (int i = 0; i < k; i++) {
                int up = q+k-upper_bound(q,q+k, p[i]-res)-(res>0);
                if(12*up < k) cout << i+1 << endl;
        }
        cout << "--------" << endl;
        for (int i = 0; i < k; i++) {
                int up = q+k-upper_bound(q,q+k,p[i]+res);
                if(12*up < k) cout << i+1 << endl;
        }
}

void input()
{
        cin >> k >> n >> m;
        for (int i = 0; i < k; i++) cin >> p[i], q[i] = p[i];
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
