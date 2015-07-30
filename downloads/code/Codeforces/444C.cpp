#include <bits/stdc++.h>
using namespace std;
#define int long long

struct segtree
{
        int N;
        vector<int> col, sum, add;
        segtree(int n)
        {
                N = 1;
                while(N < n) N <<= 1;
                col.assign(2*N-1,-1);
                sum.assign(2*N-1,0);
                add.assign(2*N-1,0);
                for (int i = 0; i < N; i++) col[N-1+i] = i+1;
        }

        void update(int a, int b, int x) { update(a,b,0,N,0,x,-1);}
        int update(int a, int b, int l, int r, int k, int x, int c)
        {
                if(c >= 0) col[k] = c;
                c = col[k];
                if(b <= l or r <= a or col[k] == x) return 0;
                int m = (l+r)/2, s = 0;
                if(a <= l and r <= b) {
                        if(col[k] >= 0) {
                                add[k] += s = abs(col[k]-x);
                                s *= r-l;
                        }
                        else s = update(a,b,l,m,2*k+1,x,c)+update(a,b,m,r,2*k+2,x,c);
                        col[k] = x;
                }
                else {
                        s = update(a,b,l,m,2*k+1,x,c)+update(a,b,m,r,2*k+2,x,c);
                        col[k] = -1;
                }
                sum[k] += s;
                return s;
        }

        int query(int a, int b) { return query(a,b,0,N,0);}
        int query(int a, int b, int l, int r, int k)
        {
                if(b <= l or r <= a) return 0;
                if(a <= l and r <= b) return sum[k];
                int m = (l+r)/2, s = min(r,b)-max(l,a);
                return query(a,b,l,m,2*k+1)+query(a,b,m,r,2*k+2)+add[k]*s;
        }
};

int n, m, t, l, r, x;

void solve()
{
        segtree st(n);
        while(m--) {
                cin >> t >> l >> r; --l;
                if(t == 1) {
                        cin >> x;
                        st.update(l,r,x);
                }
                else cout << st.query(l,r) << endl;
        }
}

void input()
{
        cin >> n >> m;
}

signed main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
