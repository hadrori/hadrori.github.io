#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
typedef pair<int,int> pii;
struct node{
    int v, d, c;
    bool operator<(const node &n)const{ return d > n.d;}
};
vector<pii> G[128];
int d[128][128];
int N, M, C;

int solve(){
    memset(d, -1, sizeof(d));
    priority_queue<node> q;
    q.push((node){0,0,0});
    while(!q.empty()){
        int v = q.top().v, td = q.top().d, c = q.top().c;
        q.pop();
        if(d[v][c] >= 0) continue;
        d[v][c] = td;
        rep(i,G[v].size()){
            int &nv = G[v][i].first, &nd = G[v][i].second;
            q.push((node){nv, td+nd, c});
            if(c < N) q.push((node){nv, td, c+1});
        }
    }
    rep(i,M) if(0 <= d[N-1][i] and d[N-1][i] <= C) return i;
    return M;
}

bool input(){
    cin >> N >> M >> C;
    rep(i,N) G[i].clear();
    rep(i,M){
        int f, t, c; cin >> f >> t >> c;
        G[f-1].pb(pii(t-1,c));
    }
    return N;
}
signed main(){
    while(input()) cout << solve() << endl;
    return 0;
}


