#include <bits/stdc++.h>
#define rep(i,a) for(int i = 0;i < (a); i++)
using namespace std;
typedef long long ll;
int n, m;
vector<ll> h, p;

bool can(ll tim){
    int cur = 0;
    rep(i,n){
        if(cur == m) break;
        ll t = p[cur];
        if(t >= h[i]){
            while(cur < m && p[cur] - h[i] <= tim) cur++;
        }
        else{
            if(h[i] - t > tim) return false;
            while(cur < m && p[cur] <= h[i]) cur++;
            while(cur < m && p[cur] - t + min(h[i] - t, p[cur] - h[i]) <= tim) cur++;
        }
    }
    return cur == m;
}

int main(){
    cin >> n >> m;
    h.resize(n); p.resize(m);
    rep(i,n) cin >> h[i];
    rep(i,m) cin >> p[i];
    
    if(m == 0){
        cout << 0 << endl;
        return 0;
    }
    
    ll lb = -1, ub = 20000000000;
    while(lb + 1 < ub){
        ll mid = (lb + ub) / 2;
        if(can(mid)) ub = mid;
        else lb = mid;
    }
    cout << ub << endl;
    return 0;
}
