#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)

int n, m, k;

bool ok(int p){
    int cnt = 0;
    rep(i,n) {
        if(m*(i+1) <= p) cnt += m;
        else cnt += p/(i+1);
    }
    return cnt >= k;
}

int solve(){
    int lb = 0, ub = n*m+1, mid;
    while(ub-lb>1){
        mid = (lb+ub)/2;
        if(ok(mid)) ub = mid;
        else lb = mid;
    }
    return ub;
}

void input(){
    cin >> n >> m >> k;
}

signed main(){
    input();
    cout << solve() << endl;
    return 0;
}
