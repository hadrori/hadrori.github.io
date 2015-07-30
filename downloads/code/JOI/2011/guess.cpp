#include <bits/stdc++.h>
using namespace std;

int n, k, a[128];

void rec(int l, int r, int idx)
{
        if(r-l == 1) {
                int p = 0;
                for (int i = 0; i < n; i++) {
                        if(!a[i] and p == l) {
                                a[i] = idx;
                                break;
                        }
                        if(!a[i]) p++;
                }
                return;
        }
        int m = (l+r)/2, p = 0;
        for (int i = 0; i < n; i++) {
                if(l <= p and p < m and !a[i]) cout << idx << endl, p++;
                else if(a[i]) cout << a[i] << endl;
                else cout << 1 << endl, p++;
        }
        cin >> k;
        if(k == n) throw 1;
        if(k == idx) rec(l,m,idx);
        else rec(m,r,idx);
}

void solve()
{
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        if(j == i) cout << 1 << endl;
                        else cout << 2 << endl;
                }
                cin >> k;
                if(k == n) return;
                if(k == 2) {
                        a[i] = 1;
                        break;
                }
        }
        for (int i = 1; i < n; i++) rec(0,n-i,i+1);
        for (int i = 0; i < n; i++) cout << a[i] << endl;
        cin >> k;
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        cin >> n;
        try {
                solve();
        } catch(int e) {}
        return 0;
}
