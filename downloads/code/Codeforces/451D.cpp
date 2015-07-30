#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
typedef long long ll;
string s;
ll ans[2], sum[100010][2][2], t[100010], n;

void solve(){
    n = s.size();
    rep(i,n){
        t[i] = s[i]-'a';
        memcpy(sum[i+1],sum[i],sizeof(sum[i]));
        ++sum[i+1][t[i]][i%2];
    }
    rep(i,n)rep(j,2) ans[j] += sum[n][t[i]][(i+j+1)%2]-sum[i][t[i]][(i+j+1)%2];
    cout << ans[0] << " " << ans[1] << endl;
}

int main(){
    cin.sync_with_stdio(0);
    cin >> s;
    solve();
    return 0;
}
