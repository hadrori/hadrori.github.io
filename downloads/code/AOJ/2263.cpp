#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define all(u) (u).begin(),(u).end()
#define pb push_back
#define INF 1e9
typedef pair<int,int> pii;

vector<pii> p;
int n;

int main(){
    cin >> n;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        p.pb(pii(b,a));
    }
    sort(all(p));
    int dp[1024][1024];
    rep(i,1024)rep(j,1024) dp[i][j] = INF;
    dp[0][0] = 0;
    
    rep(i,n)rep(j,i+1){
        dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        if(dp[i][j] + p[i].second <= p[i].first)
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + p[i].second);
    }
    int ans = 0;
    repd(i,n,0) if(dp[n][i] != INF){
        ans = i;
        break;
    }
    cout << ans << endl;
    return 0;
}
