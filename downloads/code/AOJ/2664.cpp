#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
 
struct union_find
{
    vector<int> rnk, par;
 
    union_find() {}
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
    bool same(int x, int y) {
        x = find(x); y = find(y);
        return x == y;
    }
};
 
int n, m, x[5010];
union_find uf;
map<string, int> id;
 
int solve() {
    rep(i,n) x[uf.find(i)] = min(x[uf.find(i)], x[i]);
    int ans = 0;
    rep(i,n) ans += x[uf.find(i)];
    return ans;
}
 
void input() {
    cin >> n;
    string a, b; int y;
    rep(i,n) {
        cin >> a >> y;
        x[id[a] = i] = y;
    }
    uf = union_find(n);
    cin >> m;
    rep(i,m) {
        cin >> a >> b;
        uf.unite(id[a],id[b]);
    }
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}