#include <bits/stdc++.h>
#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) (u).begin(),(u).end()

using namespace std;

string A[3];
int dp[64][2], N;
const int mod = (int)1e9 + 7;

bool input(){
    cin >> A[0];
    if(A[0] == "0") return 0;
    cin >> A[1] >> A[2];
    reverse(all(A[0]));
    reverse(all(A[1]));
    reverse(all(A[2]));
    return 1;
}

int solve(){
    memset(dp, 0, sizeof(dp));
    N = A[0].size();
    dp[0][0] = 1;
    rep(d,N){
        rep(i,10){
            if(A[0][d] != '?'){
                if(i) break;
                i = A[0][d] - '0';
            }
            if(d == N - 1 && !i)  continue;
            rep(j,10){
                if(A[1][d] != '?'){
                    if(j) break;
                    j = A[1][d] - '0';
                }
                if(d == N - 1 && !j)  continue;
                rep(k,10){
                    if(A[2][d] != '?'){
                        if(k) break;
                        k = A[2][d] - '0';
                    }
                    if(d == N - 1 && !k)  continue;
                    if((i + j) % 10 - k == 0)
                        dp[d+1][(i + j) / 10] += dp[d][0];
                    if((i + j + 1) % 10 - k == 0)
                        dp[d+1][(i + j + 1) / 10] += dp[d][1];
                    dp[d+1][0] %= mod;
                    dp[d+1][1] %= mod;
                }
            }
        }
    }
    return dp[N][0];
}

signed main(){
    while(input()){ cout << solve() << endl; }
    return 0;
}
