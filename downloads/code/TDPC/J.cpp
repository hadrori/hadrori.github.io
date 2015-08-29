#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, xs;
double dp[1<<16];

double solve() {
    repi(i,1,1<<16) {
        dp[i] = 1e9;
        repi(x,1,15) {
            double sum = 0;
            int cnt = 0;
            repi(y,x-1,x+2) {
                int j = ~(1<<y)&i;
                if(i == j) cnt++;
                else sum += dp[j];
            }
            if(cnt != 3) dp[i] = min(dp[i], (sum+3)/(3-cnt));
        }
    }
    return dp[xs];
}

void input() {
    cin >> n;
    int x;
    rep(i,n) {
        cin >> x;
        xs |= 1<<x;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
