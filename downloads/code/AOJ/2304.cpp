#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
const int inf = 1e9;
struct edge{ int to, cap, rev, id, right;};
vector<edge> G[512];
int level[512], itr[512];
int N, M, S, T;
void add_edge(int from, int to, int id){
    G[from].pb((edge){to,1,(int)G[to].size(),id,1});
    G[to].pb((edge){from,1,(int)G[from].size()-1,id,0});
}

void bfs(){
    queue<int> q;
    q.push(S);
    memset(level, -1, sizeof(level));
    level[S] = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        if(v == T) return;
        rep(i,G[v].size()){
            edge &e = G[v][i];
            if(level[e.to] < 0 and e.cap > 0){
                level[e.to] = level[v]+1;
                q.push(e.to);
            }
        }
    }
}

int dfs(int v, int f){
    if(v == T) return f;
    for(int &i = itr[v]; i < (int)G[v].size(); i++){
        edge &e = G[v][i];
        if(e.cap > 0 and level[e.to] > level[v]){
            int d = dfs(e.to, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

void solve(){
    int flow = 0, f;
    while(1){
        bfs();
        if(level[T] < 0) break;
        memset(itr, 0, sizeof(itr));
        while((f=dfs(S,inf)) > 0) flow += f;        
    }
    vector<int> ids;
    rep(i,N) rep(j,G[i].size())
        if(G[i][j].cap < 1 and G[i][j].right == 0)
            ids.pb(G[i][j].id);
    sort(all(ids));
    cout << flow << endl;
    cout << ids.size() << endl;
    rep(i,ids.size()) cout << ids[i] << endl;
}

void input(){
    cin >> N >> M;
    rep(i,M){
        int x, y; cin >> x >> y;
        x--; y--;
        add_edge(x, y, i+1);
    }
    cin >> S >> T;
    S--; T--;
}
signed main(){
    input();
    solve();
    return 0;
}


