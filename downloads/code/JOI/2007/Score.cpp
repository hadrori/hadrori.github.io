#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n, r[100010];
pii x[100010];

void solve()
{
        sort(x,x+n);
        reverse(x,x+n);
        int rnk = 0, pv = -1;
        for (int i = 0; i < n; i++) {
                if(pv != x[i].first) rnk = i+1;
                pv = x[i].first;
                r[x[i].second] = rnk;
        }
        for (int i = 0; i < n; i++)
                cout << r[i] << endl;
}

void input()
{
        cin >> n;
        for (int i = 0; i < n; i++) {
                cin >> x[i].first;
                x[i].second = i;
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
