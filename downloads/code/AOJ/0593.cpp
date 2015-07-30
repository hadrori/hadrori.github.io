#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)

int N, M, A[1024], B[1024], cnt[1024];

void input(){
    cin >> N >> M;
    rep(i,N) cin >> A[i];
    rep(i,M) cin >> B[i];
}

int solve(){
    rep(i,M) rep(j,N) if(A[j] <= B[i]){
        cnt[j]++;
        break;
    }
    int m = -1, ans;
    rep(i,N) if(m < cnt[i]) {
        m = cnt[i];
        ans = i+1;
    }
    return ans;
}

signed main(){
    input();
    cout << solve() << endl;
    return 0;
}
