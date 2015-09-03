#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

const int mod = 1000000007;
int n, c[1024][1024], dp[1024][1024], w[1024][1024];
vector<int> g[1024];

int rec(int v, int par) {
    int &ret = dp[v][par];
    if(ret) return ret;
    ret = w[v][par] = 1;
    for(int &u: g[v]) if(u != par) {
        rec(u,v);
        w[v][par] += w[u][v];
        ret = 1LL*ret*dp[u][v]%mod*c[w[v][par]-1][w[u][v]]%mod;
    }
    return ret;
}

int solve() {
    rep(i,1024) {
        c[i][0] = 1;
        repi(j,1,i+1) c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
    }

    int ans = 0;
    rep(i,n) for(int &u: g[i]) if(i < u) (ans += 1LL*rec(i,u)*rec(u,i)%mod*c[w[i][u]+w[u][i]-2][w[i][u]-1]%mod) %= mod;
    return ans;
}

void input() {
    cin >> n;
    int a, b;
    rep(i,n-1) {
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
