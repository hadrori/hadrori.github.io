#include <algorithm>
#include <iostream>

#define rep(i,a) for(int i = 0; i < (a); i++)

using namespace std;

int n, s;
int r[512], l[512], w[512][512];

void input(){
    cin >> n >> s;
    s--;
    rep(i,n) cin >> l[i] >> r[i];
    rep(i,n)rep(j,n) cin >> w[i][j];
    return;
}

void solve(){
    rep(k,n)rep(i,n)rep(j,n)
        w[i][j] = min(w[i][j], w[i][k] + w[k][j]);

    int sum[512] = {0};
    bool done[512] = {false};
    rep(i,n)if(r[i] >= w[s][i]){
        sum[i] = r[i] - max(l[i], w[s][i]);
        done[i] = true;
    }

    int ans = 0;
    rep(k,n)rep(i,n)rep(j,n)if(done[i] && r[j] >= r[i] + w[i][j]){
        sum[j] = max(sum[j], r[j] - max(l[j], r[i] + w[i][j]) + sum[i]);
        done[j] = true;
        ans = max(ans, sum[j]);
    }

    cout << ans << endl;
    return;
}

int main(){
    input();
    solve();
    return 0;
}
