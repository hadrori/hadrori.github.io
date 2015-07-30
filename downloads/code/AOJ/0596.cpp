#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define pb emplace_back
#define mp make_pair
#define fst first
#define snd second
const int inf = 1e9;

typedef pair<int,int> pii;

int N, K;
int C[5010], R[5010];
vector<int> edge[5010];
int path[5010][5010];


void dfs(int src, int pos, int cost, int res){
    if(!res) return;
    rep(i,edge[pos].size()){
        int nxt = edge[pos][i];
        if(path[src][nxt] == -1) {
            path[src][nxt] = cost;
            dfs(src, nxt, cost, res-1);
        }
    }
}

void input(){
    cin >> N >> K;
    rep(i,N) cin >> C[i] >> R[i];
    rep(j,K) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    memset(path, -1, sizeof(path));
    rep(i,N) dfs(i, i,C[i], R[i]);
}

bool visited[5010];
int dist[5010];

int solve(){
    priority_queue<pii, vector<pii>, greater<pii>> que;
    que.push(mp(0,0));
    rep(i,N) dist[i] = inf;
    while(!que.empty()){
        int pos = que.top().snd;
        int cost = que.top().fst;
        que.pop();
        if(visited[pos]) continue;
        visited[pos] = 1;
        if(pos == N-1) return cost;
        rep(i,N) if(i != pos && path[pos][i] >= 0){
            que.push(mp(cost+path[pos][i], i));
            dist[i] = cost + path[pos][i];
        }
    }
    return 0;
}

signed main(){
    input();
    cout << solve() << endl;
    return 0;
}
