#include <iostream>
#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
using namespace std;
int N, D;
int dice[3][6] = {{0,1,0,2,0,1}, {0,0,1,0,0,1}, {0,0,0,0,1,0}};

void input(){ cin >> N >> D;}
double dp[105][64][64][64]; // 2^60 ≒ 10^18

bool divisor(int x, vi &div){
    div.clear();
    div.resize(3);
    while(x % 2 == 0){
        div[0]++;
        x /= 2;
    }
    while(x % 3 == 0){
        div[1]++;
        x /= 3;
    }
    while(x % 5 == 0){
        div[2]++;
        x /= 5;
    }
    return x != 1;
}

double solve(){
    vi div;
    if(divisor(D, div)) return 0.0;
    dp[0][0][0][0] = 1.0;
    rep(n,N) rep(i,div[0]+1) rep(j,div[1]+1) rep(k,div[2]+1) { // 2^div[0] * 3^div[1] * 5^div[2]以上はまとめてよい
        if(!dp[n][i][j][k]) continue;
        rep(d,6) dp[n+1][min(div[0], i+dice[0][d])][min(div[1], j+dice[1][d])][min(div[2], k+dice[2][d])] += dp[n][i][j][k] / 6.0;
    }
    return dp[N][div[0]][div[1]][div[2]];
}

signed main(){
    input();
    printf("%.8f\n", solve());
    return 0;
}
