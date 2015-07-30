#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 2048;
int n, m, ex[M], ey[M], r[M], t[M], l[M], b[M];

void prepare()
{
        ex[0] = ey[0] = r[0] = t[0] = 1;
        for (int i = 1; i <= n; i++) {
                ex[i] = ex[i-1]-ey[i-1];
                ey[i] = ex[i-1]+ey[i-1];
                r[i] = max(r[i-1], t[i-1]+ex[i]);
                t[i] = max(t[i-1], l[i-1]+ey[i]);
                l[i] = max(l[i-1], b[i-1]-ex[i]);
                b[i] = max(b[i-1], r[i-1]-ey[i]);
                if(abs(ex[i]) > (1LL<<40) and abs(ey[i]) > (1LL<<40)) {
                        n = i;
                        break;
                }
        }
}

void rec(int x, int y, int n, vector<int> &s)
{
        if(-l[n] > x or x > r[n] or -b[n] > y or y > t[n]) return;
        if(n == 0) {
                if(x == y) s.assign(1,(x+y)/2);
                return;
        }
        rec(x,y,n-1,s);
        vector<int> t;
        rec(ey[n]-y,x-ex[n],n-1,t);
        for (vector<int>::iterator it = t.begin(); it != t.end(); it++)
                s.push_back((1LL<<n)-*it);
}

void solve()
{
        prepare();
        while(m--) {
                int tx, ty;
                scanf("%lld%lld", &tx, &ty);
                vector<int> ans;
                rec(tx,ty,n,ans);
                sort(ans.begin(),ans.end());
                ans.erase(unique(ans.begin(),ans.end()), ans.end());
                printf("%lld", (int)ans.size());
                for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
                        printf(" %lld", *it);
                puts("");
        }
}

void input()
{
        scanf("%lld%lld", &n, &m);
}

signed main()
{
        input();
        solve();
        return 0;
}
