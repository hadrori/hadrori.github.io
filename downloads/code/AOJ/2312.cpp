#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i,a,b) for(int i = a; i < b; i++)

#define INF 1000000000000

typedef long long ll;

using namespace std;

int main(){
    ll n, m, l;
    cin >> n >> m >> l;
    
    vector<ll> K(n);
    vector<ll> s(m+1);
    vector<ll> sum(m+1,0);
    
    rep(i,n) cin >> K[i];
    
    ll t = 0;
    rep(i,m){
        cin >> s[i+1];
        t += s[i+1];
        sum[i+1] = t;
    }
    
    ll ans = INF;
    
    sort(K.rbegin(),K.rend());
    vector<vector<ll> > dp(n+1,vector<ll>(n+1,INF));
    dp[0][0] = 0;
    rep(i, n) rep(j, i + 1) if(dp[i][j] < INF){
        int h = max(i, j) + 1;
        dp[h][j] = min(dp[j][h], dp[i][j] + (sum[K[i]] - sum[K[h] - 1]) / l);
        dp[h][i] = min(dp[h][i], dp[i][j] + (sum[K[j]] - sum[K[h] - 1]) / l);
    }
    rep(i, n) ans = min(ans, dp[n - 1][i] + (sum[K[i]] - sum[K[n - 1] - 1]) / l);

    cout << ans << endl;
}