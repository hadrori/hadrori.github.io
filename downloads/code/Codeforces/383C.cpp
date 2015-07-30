#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = 1e9;
const int MAX = 200010;
// BIT is 0 indexed
struct BIT{
    int bit[MAX+1], N;
    BIT(){}
    BIT(int N):N(N){
        memset(bit, 0, sizeof(bit));
    }
    // sum [0,i]
    int sum(int i){
        i++;
        int ret = 0;
        while(i){
            ret += bit[i];
            i -= i&-i;
        }
        return ret;
    }
    // sum [i,j)
    int sum(int i, int j){
        return sum(j-1) - sum(i-1);
    }    
    void add(int i, int x){
        i++;
        while(i <= N){
            bit[i] += x;
            i += i&-i;
        }
    }
};

int N, M, a[MAX], depth[MAX], in[MAX], out[MAX], par[MAX];
vector<int> G[MAX];
BIT bits[2];

void dfs(int v, int u, int &f, int &g){
    in[v] = f++;
    depth[v] = depth[u]+1;
    par[v] = u;
    for(int &w: G[v])
        if(w != u) dfs(w, v, g, f);
    out[v] = f;
}

void solve(){
    depth[0] = -1;
    int f = 0, g = 0;
    dfs(0,0,f,g);
    bits[0] = BIT(f+1);
    bits[1] = BIT(g+1);
    rep(i,N) {
        bits[depth[i]%2].add(in[i],a[i]);
        bits[depth[i]%2].add(in[i]+1,-a[i]);
    }
    int type, x, val;
    while(M--){
        cin >> type >> x;
        x--;
        if(type == 1){
            cin >> val;
            bits[depth[x]%2].add(in[x], val);
            bits[depth[x]%2].add(out[x], -val);
            for(int &v: G[x])if(v!=par[x]){
                bits[depth[v]%2].add(in[v],-val);
                bits[depth[v]%2].add(out[v],val);
            }
        }
        else cout << bits[depth[x]%2].sum(in[x]) << endl;
    }
}

void input(){
    cin >> N >> M;
    rep(i,N) cin >> a[i];
    rep(i,N-1){
        int u, v; cin >> u >> v; u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}

