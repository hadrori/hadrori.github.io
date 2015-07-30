#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
const double eps = 1e-9;
const int inf = 1e9;
typedef long long ll;
typedef pair<int,int> pii;

int n, a[100010], l, r;
ll scr[100010], dp[100010][2];

ll solve(){
    l = a[0]; r = a[0];
    rep(i,n){
        scr[a[i]] += 1LL*a[i];
        l=min(l,a[i]); r=max(r,a[i]);
    }
    ++r;
    repi(k,l,r){
        dp[k+1][1] = dp[k][0]+scr[k];
        dp[k+1][0] = max(dp[k][0], dp[k][1]);
    }
    return max(dp[r][0], dp[r][1]);
}

void input(){
    scanf("%d", &n);
    rep(i,n) scanf("%d", a+i);
}

int main(){
    input();
    cout << solve() << endl;
    return 0;
}
