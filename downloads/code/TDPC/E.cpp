#include <iostream>
#include <string>
#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
using namespace std;
const int mod = 1000000007;

string N;
int D;
int dp[10010][100][2];

void input(){ cin >> D >> N;}

int solve(){
    int T = N.size();
    dp[0][0][0] = 1;
    rep(i,T) rep(j,D) rep(k,2) rep(d,10){
        if(k == 0 && d > N[i] - '0') break;
        int nj = (j + d) % D;
        int nk ;
        if(k == 0 && d < N[i] - '0') nk = 1;
        if(k == 0 && d >= N[i] - '0') nk = 0;
        if(k == 1) nk = 1;
        dp[i+1][nj][nk] += dp[i][j][k];
        dp[i+1][nj][nk] %= mod;
    }
    return (dp[T][0][1] - 1 + mod) % mod;
}

signed main(){
    input();
    cout << solve() << endl;
    return 0;
}
