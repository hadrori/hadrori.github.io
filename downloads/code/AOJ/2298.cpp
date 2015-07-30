#include <bits/stdc++.h>
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
using namespace std;
int N, K, T, U, V, L;
int D[10010];

int main(){
    cin >> N >> K >> T >> U >> V >> L;
    rep(i,N){
        int t; cin >> t;
        D[t]++;
    }
    int have = 0;
    double ans = 0;
    int res = 0, prev = 0, pos = 0;
    repi(i,1,L+1){
        if(res){
            res--;
            ans += 1.0 / V;
        }
        else ans += 1.0 / U;
        if(have && !res) {
            have--;
            res = V * T;
        }
        if(D[i]) {
            if(!res) {
                D[i]--;
                res = V * T;
            }
            if(have + D[i] > K){
                D[i]--;
                res = V * T;
                have = K;
            }
            else have += D[i];
        }
    }
    printf("%.8f\n", ans);
    return 0;
}
