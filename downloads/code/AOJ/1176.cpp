#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
const int inf = 1e9;
typedef pair<int,int> pii;
int H, W, S, lim;
int cst[32][32], sum[33][33];
int need[33][33][33][33], group[33][33][33][33];

pii rec(int li, int lj, int ri, int rj){
    if(need[li][lj][ri][rj] >= 0) return pii(group[li][lj][ri][rj],need[li][lj][ri][rj]);
    int s = 0;
    repi(i,li,ri) s += sum[i][rj] - sum[i][lj];
    if(s < lim){
        need[li][lj][ri][rj] = inf;
        group[li][lj][ri][rj] = 0;
        return pii(group[li][lj][ri][rj],need[li][lj][ri][rj]);
    }
    pii ret = pii(1, s);
    repi(i,li+1,ri) {
        pii t = rec(li,lj,i,rj);
        pii u = rec(i,lj,ri,rj);
        t.first += u.first; t.second = min(t.second, u.second);
        ret = max(ret, t);
    }
    repi(j,lj+1,rj) {
        pii t = rec(li,lj,ri,j);
        pii u = rec(li,j,ri,rj);
        t.first += u.first; t.second = min(t.second, u.second);
        ret = max(ret, t);
    }

    group[li][lj][ri][rj] = ret.first;
    need[li][lj][ri][rj] = ret.second;
    return ret;
}

void solve(){
    memset(group,-1,sizeof(group));
    memset(need,-1,sizeof(need));
    int s = 0;
    rep(i,H) {
        sum[i][0] = 0;
        rep(j,W) sum[i][j+1] = sum[i][j]+cst[i][j];
        s += sum[i][W];
    }
    lim = s - S;
    pii ans = rec(0,0,H,W);
    cout << ans.first << " " << ans.second-lim << endl;
}

bool input(){
    cin >> H >> W >> S;
    if(!H or !W or !S) return 0;
    rep(i,H) rep(j,W) cin >> cst[i][j];
    return 1;
}
signed main(){
    while(input()) solve();
    return 0;
}


