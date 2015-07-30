#include <bits/stdc++.h>
using namespace std;

struct segtree
{
        int N;
        vector<int> val, sum, add, flt;
        segtree(int n) {
                N = 1;
                while(N < n) N *= 2;
                sum.assign(2*N, 0);
                add.assign(2*N, 0);
                flt.assign(2*N, 0);
                init(0,n,0,N,0);
        }
        void init(int a, int b, int l, int r, int k){
                if(b <= l or r <= a) return;
                if(a <= l and r <= b) flt[k] = 1;
                sum[k] = min(r,b)-max(l,a);
                if(r-l==1) return;
                init(a,b,l,(l+r)/2,2*k+1);
                init(a,b,(l+r)/2,r,2*k+2);
        }

        int addi(int a, int b, int l, int r, int k, int x) {
                if(b <= l or r <= a) return 0;
                int s = 0;
                if(a <= l and r <= b) {
                        add[k] += x;
                        s = x*(r-l);
                }
                else {
                        flt[k] = 0;
                        int m = (l+r)/2;
                        s = addi(a,b,l,m,2*k+1,x)+addi(a,b,m,r,2*k+2,x);
                }
                sum[k] += s;
                return s;
        }

        void update(int a, int b, int c) { update(a,b,c,0,N,0);}
        void update(int a, int b, int c, int l, int r, int k) {
                if(b <= l or r <= a) return;
                if(a <= l and r <= b and flt[k]) {
                        addi(a+c-r,a+c-l,0,N,0,query(l,r)/(r-l));
                        return;
                }
                int m = (l+r)/2;
                update(a,b,c,l,m,2*k+1);
                update(a,b,c,m,r,2*k+2);
        }

        int query(int a, int b){ return query(a, b, 0, N, 0);}
        int query(int a, int b, int l, int r, int k) {
                if(b <= l or r <= a) return 0;
                if(a <= l and r <= b) return sum[k];
                int m = (l+r)/2, w = min(r,b)-max(l,a);
                return query(a,b,l,m,2*k+1)+query(a,b,m,r,2*k+2)+add[k]*w;
        }
};

int n, q, bl, br, t, p, l, r, dir;

void solve()
{
        segtree st(n);
        bl = 0; br = n;
        dir = 0;
        while(q--){
                scanf("%d", &t);
                if(t == 1){
                        scanf("%d", &p);
                        if((br-bl)/2<p) {
                                p = (br-bl)-p;
                                dir ^= 1;
                        }
                        if(!dir) {
                                st.update(bl,bl+p,bl+2*p);
                                bl += p;
                        }
                        else {
                                st.update(br-p,br,br-p);
                                br -= p;                                
                        }
                }
                else {
                        scanf("%d%d", &l, &r);
                        if(!dir) printf("%d\n", st.query(l+bl,r+bl));
                        else printf("%d\n", st.query(br-r,br-l));
                }
        }
}

void input()
{
        scanf("%d%d", &n, &q);
}

int main()
{
        input();
        solve();
        return 0;
}
