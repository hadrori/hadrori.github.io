#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
const int inf = 1e16;
struct skill{ int cst, dmg, mode;};
int N, M, HP[128], MH, ans;
skill S[128];
int dp[2][100010];
inline void chmin(int &a, int b){ a = min(a,b);}
inline void chmax(int &a, int b){ a = max(a,b);}

int solve(){
    rep(i,2) fill(dp[i], dp[i]+MH+1, inf);
    dp[0][0] = dp[1][0] = 0;
    rep(i,M){
        int c = S[i].cst, d = S[i].dmg, m = S[i].mode;
        for(int j = 0; j < MH; j++)
            chmin(dp[m][min(MH,j+d)], dp[m][j]+c);
    }
    for(int j = MH, pr = inf; j > 0; j--){
        chmin(pr, dp[1][j]); chmin(dp[1][j], pr);
    }
    ans = inf;
    rep(a,MH+1){
        int cst = dp[0][a];
        if(cst == inf) continue;
        rep(i,N) cst += dp[1][max(HP[i]-a,0LL)];
        chmin(ans, cst);
    }
    return ans;
}

bool input(){
    cin >> N;
    if(!N) return 0;
    MH = 0;
    rep(i,N){
        cin >> HP[i];
        chmax(MH, HP[i]);
    }
    cin >> M;
    rep(i,M){
        string a, b;
        cin >> a >> S[i].cst >> b >> S[i].dmg;
        S[i].mode = (b == "Single");
    }
    return 1;
}

signed main(){
    while(input()) cout << solve() << endl;
    return 0;
}
