#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int MAX = 1<<18;
struct union_find
{
        int rnk[MAX], par[MAX];
        
        union_find(int n){
                for(int i = 0; i < n; i++) {
                        rnk[i] = 1;
                        par[i] = i;
                }
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
        bool same(int x, int y) {
                x = find(x); y = find(y);
                return x == y;
        }
};

int n, m, ans[MAX], hand[MAX][2], query[2*MAX][2];
vector<int> group[MAX];

void merge_vec(int u, int v)
{
        vector<int> &a = group[u], &b = group[v];
        if (a.size() < b.size()) a.swap(b);
        a.insert(a.end(), b.begin(), b.end());
        b.clear();
}

void update(union_find &uf, int u, int v, int t)
{
        u = uf.find(u); v = uf.find(v);
        if(u == v) return;
        if(uf.same(0,u) or uf.same(0,v)) {
                if(uf.same(0,v)) swap(u,v);
                for (vector<int>::iterator it = group[v].begin(); it != group[v].end(); it++) ans[*it] = t;
        }
        uf.unite(u,v);
        if(uf.find(u) == u) merge_vec(u, v);
        else merge_vec(v, u);
}

void solve()
{
        union_find uf(n);
        for (int i = 0; i < n; i++)
                for (int j = 0; j < 2; j++)
                        if(hand[i][j] >= 0) update(uf,i,hand[i][j],-1);

        for (int i = m-1; i >= 0; i--) update(uf,query[i][0],query[i][1],i);
        
        for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
}

void input()
{
        ans[0] = -1;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++){
                group[i].assign(1,i);
                for (int j = 0; j < 2; j++) {
                        scanf("%d", &hand[i][j]);
                        if(hand[i][j] > 0) hand[i][j]--;
                }
        }
        int a, b;
        for (int i = 0; i < m; i++) {
                scanf("%d%d", &a, &b); a--; b--;
                query[i][0] = a;
                query[i][1] = hand[a][b];
                hand[a][b] = -1;
        }
}

int main()
{
        input();
        solve();
        return 0;
}
