#include <bits/stdc++.h>
using namespace std;

struct union_find
{
        vector<int> rnk, par;
        
        union_find(int n){
                rnk.assign(n,1);
                par.assign(n,0);
                for(int i = 0; i < n; i++) par[i] = i;
        }
        
        int find(int x) {
                if(x == par[x]) return x;
                else return par[x] = find(par[x]);
        }
        void unite(int x, int y) {
                x = find(x); y = find(y);
                if(x == y) return;
                if(rnk[x] > rnk[y]) par[y] = x;
                else {
                        par[x] = y;
                        if(rnk[x] == rnk[y]) rnk[y]++;
                }
        }
        bool same(int x, int y){ return find(x)==find(y);}
};

struct edge
{
        int u, v, c;
        bool operator<(const edge &e)const{ return c < e.c;}
};

int n, m, k;
vector<edge> es;

int solve()
{
        sort(begin(es),end(es));
        union_find uf(n);
        int f = n, ans = 0;
        for(auto &e: es) {
                if(f <= k) break;
                if(uf.same(e.u,e.v)) continue;
                uf.unite(e.u,e.v);
                f--;
                ans += e.c;
        }
        return ans;
}

void input()
{
        cin >> n >> m >> k;
        for (int i = 0; i < m; i++) {
                int u, v, c;
                cin >> u >> v >> c;
                es.push_back((edge){u-1,v-1,c});
        }
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
