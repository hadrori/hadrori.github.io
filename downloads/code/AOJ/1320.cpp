#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
const int inf = 1e9;

int N;
string inp[16];
vector<string> names;
int tail[16][16];
int dp[1<<14][16];

void mymin(int &a, int b){
    if(a == -1) a = b;
    else a = min(a, b);
}

int solve(){
    bool use[16];
    memset(use,-1,sizeof(use));
    rep(i,N) rep(j,N)
        if(i != j and use[j] and inp[j].find(inp[i]) != string::npos)
            use[i] = 0;
    names.clear();
    rep(i,N) if(use[i]) names.pb(inp[i]);
    N = names.size();
    rep(i,N) rep(j,N) if(i != j){
        int n = names[i].size(), m = names[j].size();
        for(int k = min(n, m); k >= 0; k--)
            if(names[i].substr(n-k,k) == names[j].substr(0,k)){
                tail[i][j] = m-k;
                break;
            }
    }
    memset(dp,-1,sizeof(dp));
    rep(i,N) dp[1<<i][i] = names[i].size();
    rep(S,1<<N) rep(u,N) if(S&(1<<u))
        rep(v,N) if(!(S&(1<<v)))
            mymin(dp[S|(1<<v)][v], dp[S][u]+tail[u][v]);
    int ans = inf;
    rep(i,N) mymin(ans, dp[(1<<N)-1][i]);
    return ans;
}

bool input(){
    cin >> N;
    if(!N) return 0;
    rep(i,N) cin >> inp[i];
}
signed main(){
    while(input()){ cout << solve() << endl;}
    return 0;
}


