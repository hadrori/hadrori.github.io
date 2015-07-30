#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back

const int mod = 1e9+7;
const int MAX = 400000;
inline int f(int a, int b){return 1LL*a*b%mod;}
inline int g(int a, int b){return (a+b)%mod;}
inline int h(int a, int b){return (a-b+mod)%mod;}

// 0 indexed
struct BIT{
    int bit[MAX+1], N;
    
    BIT(int N):N(N){
        memset(bit, 0, sizeof(bit));
    }
    // sum [0,i]
    int sum(int i){
        i++;
        int ret = 0;
        while(i){
            ret = g(ret, bit[i]);
            i -= i&-i;
        }
        return ret;
    }
    // sum [i,j)
    int sum(int i, int j){
        return h(sum(j-1),sum(i-1));
    }
    
    void add(int i, int x){
        i++;
        while(i <= N){
            bit[i] = g(bit[i], x);
            i += i&-i;
        }
    }
};

vector<int> E[MAX];
int N, M, dep[MAX], in[MAX], out[MAX]; // subtree : [in[v], out[v])

void build_inout(int v, int &idx, int d){
    in[v] = idx++;
    dep[v] = d;
    for(int &u: E[v])
        build_inout(u, idx, d+1);
    out[v] = idx;
}

void solve(){
    int idx = 0, v, w, k, q;
    build_inout(0,idx,0);
    BIT x(N), y(N);
    cin >> M;
    while(M--){
        cin >> q >> v; v--;
        int l = in[v], r = out[v], d = dep[v];
        if(q == 1){
            cin >> w >> k;
            int wei = g(w,f(d,k));
            x.add(l,wei);
            x.add(r,h(0,wei));
            y.add(l,k);
            y.add(r,h(0,k));
        }
        else cout << h(x.sum(l),f(d,y.sum(l))) << endl;
    }
}

void input(){
    cin >> N;
    int p;
    rep(i,N-1){
        cin >> p;
        E[p-1].pb(i+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
