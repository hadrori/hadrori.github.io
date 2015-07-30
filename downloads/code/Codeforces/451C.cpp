#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
typedef long long ll;
const ll e[] = {-1,1}, f[] = {-1,1};
ll n, k, d[2];

string solve(){
    bool ok = 0;
    if(n%3) return "no";
    rep(i,2)rep(j,2){
        ll x = k-2*e[i]*d[0]-f[j]*d[1];
        if(x%3) continue;
        x /= 3;
        ll y = x+e[i]*d[0], z = y+f[j]*d[1];
        if(x >= 0 and y >= 0 and z >= 0 and x <= n/3 and y <= n/3 and z <= n/3 and x+y+z==k) ok = 1;
    }
    return ok? "yes": "no";
}

void input(){
    cin >> n >> k >> d[0] >> d[1];
}

int main(){
    cin.sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        input();
        cout << solve() << endl;
    }
    return 0;
}
