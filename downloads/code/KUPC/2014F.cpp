#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
const double eps = 1e-8;
const int inf = INT_MAX;
const int r = 2829;
typedef pair<int,int> pii;

int N, x[1024], y[1024], c[1024], d[1024];
vector<pii> E[1024];
int dp[1024][4096];

void dfs(int v, int u){
    for(pii &e: E[v])
        if(e.first != u)
            dfs(e.first,v);
    dp[v][r] = inf;
    for(int i = r-1; i >= 0; i--){
        int sum = max(0,i*c[v]);
        for(pii &e: E[v])
            if(e.first != u)
                sum += dp[e.first][max(0,e.second-i)];
        dp[v][i] = min(dp[v][i+1],sum);
    }
}

int solve(){
    dfs(0,0);
    return dp[0][0];
}

inline int dist(int i, int j){ return (int)(hypot(x[i]-x[j],y[i]-y[j])+1-eps);}

void input(){
    cin >> N;
    rep(i,N) cin >> x[i] >> y[i];
    rep(i,N) cin >> d[i] >> c[i];
    rep(i,N-1){
        int a, b;
        cin >> a >> b; a--; b--;
        int k = dist(a,b)-d[a]-d[b];
        E[a].pb(pii(b,k));
        E[b].pb(pii(a,k));
    }
}

int main(){
    ios::sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
