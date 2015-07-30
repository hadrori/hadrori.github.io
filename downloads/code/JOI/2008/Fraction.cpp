#include <bits/stdc++.h>
using namespace std;

int m, k, n, d, idx;

void farey(int ln, int ld, int rn, int rd)
{
        int mn = ln+rn, md = ld+rd;
        if(md > m) return;
        if(idx > k) return;
        farey(ln,ld,mn,md);
        if(++idx == k) {
                n = mn; d = md;
                return;
        }
        farey(mn,md,rn,rd);
}

void solve()
{
        farey(0,1,1,1);
        if(!d) puts("-1");
        else cout << n << " " << d << endl;
}

void input()
{
        cin >> m >> k;
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
