#include <bits/stdc++.h>

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
using namespace std;

typedef long long ll;

int N, T;
int level[100010];
const int mod = 1000000007;

int main(){
    cin >> N >> T;
    rep(i,N) cin >> level[i];
    sort(level,level+N);
    ll ans = 1;
    rep(i,N) ans = ans * (upper_bound(level,level+i,level[i]) - lower_bound(level,level+i,level[i]-T) + 1) % mod;
    cout << ans << endl;
    return 0;
}
