#include <bits/stdc++.h>
using namespace std;

const int MAX = 10010;

struct union_find
{
        int rnk[MAX], par[MAX];
        
        union_find(int n){ for(int i = 0; i < n; i++) rnk[i] = 1, par[i] = i;}
        
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

int n, m;

int solve()
{
        union_find uf(n);
        for (int i = 0; i < m; i++) {
                int a, b; cin >> a >> b;
                uf.unite(a-1,b-1);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
                for (int j = i+1; j < n; j++)
                        if(!uf.same(i,j)) {
                                ans++;
                                uf.unite(i,j);
                        }
        
        return ans;
}

void input()
{
        cin >> n >> m;
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
