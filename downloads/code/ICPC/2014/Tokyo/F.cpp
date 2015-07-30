#include <bits/stdc++.h>
using namespace std;


struct edge
{
        int from, to, cst;
        edge(int from, int to, int cst):from(from),to(to),cst(cst){}
        bool operator==(const edge &e)const{return from==e.from and to==e.to and cst == e.cst;}
        bool operator<(const edge &e)const{return cst < e.cst;}
};

const int MAX = 512;
struct union_find
{
        int rnk[MAX], par[MAX];
        
        union_find(int n){ for(int i = 0; i < n; i++) rnk[i] = 1, par[i] = i;}
        
        int find(int x){
                if(x == par[x]) return x;
                else return par[x] = find(par[x]);
        }
        void unite(int x, int y){
                x = find(x); y = find(y);
                if(x == y) return;
                if(rnk[x] > rnk[y]) par[y] = x;
                else{
                        par[x] = y;
                        if(rnk[x] == rnk[y]) rnk[y]++;
                }
        }
        bool same(int x, int y){
                x = find(x); y = find(y);
                return x == y;
        }
};

int n, m;

int kruskal(vector<edge> &es, vector<edge> &tree, edge rm)
{
        sort(begin(es), end(es));
        tree.clear();
        union_find uf(n) ;
        int w = 0;
        for(auto &e: es) {
                if(e==rm or uf.same(e.from, e.to)) continue;
                uf.unite(e.from, e.to);
                w += e.cst;
                tree.push_back(e);
        }
        for (int i = 0; i < n; i++)
                if(!uf.same(0,i)) return 1e9;
        return w;
}

vector<edge> es, used, tmp;

void solve()
{
        int w = kruskal(es,used,edge(-1,-1,-1));
        int ans = 0, cnt = 0;
        for(auto &e: used) {
                if(w < kruskal(es,tmp,e)) {
                        cnt++;
                        ans += e.cst;
                }
        }
        cout << cnt << " " << ans << endl;
}

void input()
{
        cin >> n >> m;
        int a, b, c;
        for (int i = 0; i < m; i++) {
                cin >> a >> b >> c;
                es.push_back(edge(a-1,b-1,c));
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
