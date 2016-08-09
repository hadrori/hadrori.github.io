#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
inline void chmin(int &x, int y) { x = min(x, y); }
using i64 = int64_t;
const int inf = 1e9, N = 12000;

int ans[N+10];

bool dfs(int v, int p, int s, int l) {
    if (p-s+l > N) return 1;
    chmin(ans[p-s+l], p);
    repi(i,v,N+1) if(dfs(i,p*i,s+i,l+1)) break;
    return 0;
}

void solve() {
    fill(ans, ans+N+1, inf);
    repi(i,2,N+1) dfs(i,i,i,1);
    sort(ans+2, ans+N+1);
    cout << accumulate(ans+2, unique(ans+2, ans+N+1), 0) << endl;
}

int main() {
    solve();
    return 0;
}
