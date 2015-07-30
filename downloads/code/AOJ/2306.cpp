#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i=0;i<(int)(a);i++)
#define repit(i,a) for(auto i=begin(a);i!=end(a);i++)
int G[128][128], N, M, fr[128];
vector<int> cand;

int calc(){
    int ret = 0, x;
    repit(i,cand){
        x = 1e9;
        repit(j,cand) if(i!=j) x = min(x,G[*i][*j]);
        ret += x;
    }
    return ret;
}

int rec(int v, int inv){
    if(inv==0) return calc();
    if(v==N) return 0;
    if(fr[v] < inv-1) return rec(v+1,inv);
    repit(i,cand) if(!G[*i][v]) return rec(v+1,inv);
    cand.push_back(v);
    int ret = rec(v+1,inv-1);
    cand.pop_back();
    return max(ret,rec(v+1,inv));
}

int solve(){
    int ans = 0;
    for(int i = 2; i*(i-1)/2<=M; i++)
        ans = max(ans,rec(0,i));
    return ans;
}

void input(){
    cin >> N >> M;
    rep(i,M){
        int u, v, f; cin >> u >> v >> f;
        u--; v--;
        G[u][v] = G[v][u] = f;
        fr[u]++; fr[v]++;
    }
}

int main(){
    input();
    cout << solve() << endl;
    return 0;
}

