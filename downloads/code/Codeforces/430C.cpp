#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
const int MAX = 100010;

vector<int> G[MAX], ans;
int N, s[MAX], t[MAX];


void dfs(int v, int u, int f, int g){
    if((s[v]^f) != t[v]) ans.pb(v+1), f ^= 1;
    for(int &w: G[v])if(w != u) dfs(w,v,g,f);
}

void solve(){
    dfs(0,-1,0,0);
    cout << ans.size() << endl;
    for(int &v: ans) cout << v << endl;
}

void input(){
    cin >> N;
    rep(i,N-1){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    rep(i,N) cin >> s[i];
    rep(i,N) cin >> t[i];
}

int main(){
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
