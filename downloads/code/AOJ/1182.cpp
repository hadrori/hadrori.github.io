#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i = 0; i < (int)(a); i++)
const int inf = 1e9;

int N, M, C, s, g;
int dist[32][128][128], p[32], q[32][64], r[32][64];
int fare[32][20010], cst[128][128];

int solve(){
    rep(c,C)rep(k,N)rep(i,N)rep(j,N)
        dist[c][i][j] = min(dist[c][i][j], dist[c][i][k]+dist[c][k][j]);
    rep(c,C){
        int cur = 0; fare[c][0] = 0;
        rep(i,20000){
            if(cur < p[c]-1 and i == q[c][cur]) cur++;
            fare[c][i+1] = fare[c][i] + r[c][cur];
        }
    }
    rep(i,N)rep(j,N) cst[i][j] = inf;
    rep(c,C)rep(i,N)rep(j,N) if(dist[c][i][j] < inf) cst[i][j] = min(cst[i][j], fare[c][dist[c][i][j]]);
    rep(k,N)rep(i,N)rep(j,N) cst[i][j] = min(cst[i][j], cst[i][k]+cst[k][j]);
    return cst[s][g]==inf? -1: cst[s][g];
}

bool input(){
    cin >> N >> M >> C >> s >> g;
    s--; g--;
    rep(c,C)rep(i,N)rep(j,N) dist[c][i][j] = inf;
    rep(i,M){
        int x, y, d, c;
        cin >> x >> y >> d >> c;
        x--; y--; c--;
        dist[c][x][y] = dist[c][y][x] = min(dist[c][x][y], d);
    }
    rep(c,C) cin >> p[c];
    rep(c,C) {
        rep(i,p[c]-1) cin >> q[c][i];
        rep(i,p[c]) cin >> r[c][i];
    }
    return N;
}

int main(){
    while(input()) cout << solve() << endl;
    return 0;
}
