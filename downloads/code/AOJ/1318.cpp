#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
const int inf = 1e9;
typedef pair<int,int> pii;
int N, M, cap;
struct node{
    int v, d, c;
    bool operator<(const node &n)const{ return d > n.d;}
};
map<string,int> id;
bool gas[6010];
int dist[6010][2010];
vector<pii> G[6010];

int solve(){
    memset(dist, -1, sizeof(dist));
    priority_queue<node> que;
    que.push((node){0,0,cap});
    while(!que.empty()){
        int v = que.top().v, d = que.top().d, c = que.top().c;
        que.pop();
        if(gas[v]) c = cap;
        if(dist[v][c] >= 0) continue;
        bool ok = 1;
        repi(i,c+1,cap+1) if(dist[v][i] >= 0 and dist[v][i] < d) {
            ok = 0;
            break;
        }
        if(!ok) continue;
        dist[v][c] = d;
        if(v == 1) break;
        rep(i,G[v].size()) if(c >= G[v][i].second)
            que.push((node){G[v][i].first, d+G[v][i].second, c-G[v][i].second});
    }
    int ans = inf;
    rep(i,cap+1) if(dist[1][i] >= 0) ans = min(ans, dist[1][i]);
    if(ans == inf) ans = -1;
    return ans;
}

bool input(){
    cin >> N >> M >> cap;
    cap *= 10;
    if(!N and !M and !cap) return 0;
    string s, t; cin >> s >> t;
    id.clear();
    id[s] = 0; id[t] = 1;
    rep(i,6010) G[i].clear();
    rep(i,N){
        int d;
        cin >> s >> t >> d;
        if(!id.count(s)) id[s] = id.size()-1;
        if(!id.count(t)) id[t] = id.size()-1;
        G[id[s]].pb(pii(id[t],d));
        G[id[t]].pb(pii(id[s],d));
    }
    memset(gas, 0, sizeof(gas));
    rep(i,M){
        cin >> s;
        gas[id[s]] = 1;
    }
    return 1;
}
signed main(){
    while(input()){ cout << solve() << endl;}
    return 0;
}


