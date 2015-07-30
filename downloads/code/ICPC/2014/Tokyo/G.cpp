#include <bits/stdc++.h>
using namespace std;

struct segtree
{
        int N;
        vector<int> dat, sum;
        segtree(int n)
        {
                N = 1;
                while(N < n) N <<= 1;
                dat.assign(2*N-1,0);
                sum.assign(2*N-1,0);                
        }
        void add(int a, int b, int x) { add(a,b,x,0,0,N);}
        int add(int a, int b, int x, int k, int l, int r)
        {
                if(b <= l or r <= a) return dat[k];
                if(a <= l and r <= b) {
                        sum[k] += x;
                        return dat[k] += x;
                }
                int m = (l+r)/2;
                return dat[k] = min(add(a,b,x,2*k+1,l,m),add(a,b,x,2*k+2,m,r))+sum[k];
        }
        int minimum(int a, int b) { return minimum(a,b,0,0,N);}
        int minimum(int a, int b, int k, int l, int r)
        {
                if(b <= l or r <= a) return 1e9;
                if(a <= l and r <= b) return dat[k];
                int m = (l+r)/2;
                return min(minimum(a,b,2*k+1,l,m),minimum(a,b,2*k+2,m,r))+sum[k];
        }
};

int n, m;
string s;
set<int> ps;

void solve()
{
        segtree st(n+1);
        for(int i = 0; i < n; i++) {
                if(s[i]=='(') st.add(i+1,n+1,1);
                else {
                        ps.insert(i+1);
                        st.add(i+1,n+1,-1);
                }
        }
        while(m--) {
                int p; cin >> p;
                if(s[p-1] == '(') {
                        s[p-1] = ')';
                        st.add(p,n+1,-2);
                        ps.insert(p);
                        cout << *begin(ps) << endl;
                        st.add(*begin(ps),n+1,2);
                        s[*begin(ps)-1] = '(';
                        ps.erase(begin(ps));
                }
                else {
                        ps.erase(p);
                        st.add(p,n+1,2);
                        s[p-1] = '(';
                        int lb = 0, ub = n, mid;
                        while(ub-lb>1) {
                                mid = (lb+ub)/2;
                                if(st.minimum(mid,n+1) >= 2) ub = mid;
                                else lb = mid;
                        }
                        while(s[ub-1] != '(') ub++;
                        st.add(ub,n+1,-2);
                        s[ub-1] = ')';
                        ps.insert(ub);
                        cout << ub << endl;
                }
        }
}

void input()
{
        cin >> n >> m;
        cin >> s;
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
