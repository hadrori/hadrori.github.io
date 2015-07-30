#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
const string dir = "URDL";
const int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
int iHP, mHP, R, C, T, S, P, N;
int p[16], dmg[32], stp[1024], damage[1024], dp[1024][1<<12];
char a[128][128], d[1024];
inline bool in(int i, int j){ return i >= 0 and i < R and j >= 0 and j < C;}
inline void f(int &a, int b){a=max(a,b);}

bool solve(){
    int r = 0, c = 0, sum = 0; N = 0;
    rep(s,S)rep(_,stp[s]){
        r += dr[dir.find(d[s])]; c += dc[dir.find(d[s])];
        if(!in(r,c)) return 0;
        damage[N++] = dmg[a[r][c]-'A'];
    }
    memset(dp,0,sizeof(dp));
    dp[0][0] = iHP;
    rep(i,N)rep(S,1<<P)if(dp[i][S]){
        f(dp[i+1][S], dp[i][S]-damage[i]);
        rep(v,P)if(!(S&(1<<v))){
            f(dp[i][S|(1<<v)], min(mHP,dp[i][S]+p[v]));
            f(dp[i+1][S|(1<<v)], min(mHP,dp[i][S]+p[v])-damage[i]);
        }
    }
    rep(i,1<<P) if(dp[N][i] > 0) return 1;
    return 0;
}

bool input(){
    cin >> iHP >> mHP;
    if(!iHP and !mHP) return 0;
    cin >> R >> C;
    rep(i,R) cin >> a[i];
    cin >> T;
    rep(i,T) {
        char c; cin >> c;
        cin >> dmg[c-'A'];
    }
    cin >> S;
    rep(i,S) cin >> d[i] >> stp[i];
    cin >> P;
    rep(i,P) cin >> p[i];
    return 1;
}
int main(){
    while(input())
        cout << (solve()? "YES": "NO") << endl;
    return 0;
}


