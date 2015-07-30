#include <algorithm>
#include <iostream>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define INF 1e9
int q, n;
int path[40010], dp[40010];

int main(){
    cin >> q;
    while(q--){
        scanf("%d", &n);
        rep(i,n) scanf("%d", &path[i]);
        rep(i,n) dp[i] = INF;
        rep(i,n) *lower_bound(dp,dp+n,path[i]) = path[i];
        cout << lower_bound(dp,dp+n,INF) - dp << endl;
    }
    return 0;
}

