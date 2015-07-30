#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

struct segtree
{
        int N;
        vector<int> add;
        vector<pii> dat;
        segtree(int n) {
                N = 1;
                while(N < n) N *= 2;
                dat.assign(2*N-1, pii(0,0));
                init(0,N,0);
                add.assign(2*N-1, 0);
        }

        void init(int l, int r, int k)
        {
                dat[k].second = -l;
                if(r-l==1) return;
                init(l,(l+r)/2,2*k+1);
                init((l+r)/2,r,2*k+2);
        }

        void update(int a, int b, int x) { update(a,b,0,N,0,x);}
        pii update(int a, int b, int l, int r, int k, int x) {
                if(r <= a or b <= l) return pii(-1,-1);
                if(a <= l and r <= b) {
                        add[k] += x;
                        dat[k].first += x;
                        return dat[k];
                }
                int m = (l+r)/2;
                pii tmp = max(update(a,b,l,m,2*k+1,x), update(a,b,m,r,2*k+2,x));
                tmp.first += add[k];
                dat[k] = max(dat[k], tmp);
                return dat[k];
        }

        pii query(int a, int b){
                pii ret = query(a, b, 0, N, 0);
                ret.second *= -1;
                return ret;
        }
        pii query(int a, int b, int l, int r, int k) {
                if(r <= a or b <= l) return pii(-1,-1);
                if(a <= l and r <= b) return dat[k];
                int m = (l + r) / 2;
                pii ret = max(query(a, b, l, m, k*2+1), query(a, b, m, r, k*2+2));
                ret.first += add[k];
                return ret;
        }
};

struct wall
{
        int y, l, r;
        bool operator<(const wall &a)const{
                if(y != a.y) return y < a.y;
                return l < a.l;
        }
};

int n, m;
vector<wall> obj;
vector<pii> ans;
priority_queue<pii, vector<pii>, greater<pii>> weap;

void solve()
{
        sort(begin(obj),end(obj));
        segtree st(100000);
        ans.assign(m, pii(-2,-2));
        for(auto &o: obj) {
                pii p = st.query(o.l, o.r);
                while(!weap.empty()) {
                        pii q = weap.top();
                        if(q.first > p.first) break;
                        weap.pop();
                        ans[q.second] = pii(p.second, o.y);
                }
                st.update(o.l, o.r, 1);
        }
        for(auto &e: ans) cout << e.first+1 << " " << e.second+1 << endl;
}

void input()
{
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
                int x, y, w;
                cin >> x >> y >> w;
                obj.push_back((wall){y-1,x-1,x-1+w});
        }
        for (int i = 0; i < m; i++) {
                int a; cin >> a;
                weap.push(pii(a,i));
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
