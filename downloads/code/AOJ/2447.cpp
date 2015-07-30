#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
const int di[] = {1,0,-1,0}, dj[] = {0,1,0,-1};
struct state{ int i, j, f, used;};
int stage[2][64][64], sw[64][64];
int si, sj, ti, tj, W, H, S;
int dist[64][64][2][1024];

int solve(){
    memset(dist, -1, sizeof(dist));
    queue<state> q;
    q.push((state){si,sj,0,0});
    dist[si][sj][0][0] = 0;
    while(!q.empty()){
        state s = q.front(); q.pop();
        int dis = dist[s.i][s.j][s.f][s.used];
        if(s.i == ti and s.j == tj and
           s.f == __builtin_popcount(sw[s.i][s.j]&s.used)%2) return dis;
        
        if(stage[0][s.i][s.j] == 10 and dist[s.i][s.j][s.f^1][s.used] < 0){
            dist[s.i][s.j][s.f^1][s.used] = dis+1;
            q.push((state){s.i,s.j,s.f^1,s.used});
        }
        int cf = (s.f+__builtin_popcount(sw[s.i][s.j]&s.used))%2;
        if(0 <= stage[cf][s.i][s.j] and stage[cf][s.i][s.j] < 10){
            int nu = s.used ^ (1<<stage[cf][s.i][s.j]), nf = s.f;
            if(sw[s.i][s.j] & (1<<stage[cf][s.i][s.j])) nf ^= 1;
            if(dist[s.i][s.j][nf][nu] < 0){
                dist[s.i][s.j][nf][nu] = dis+1;
                q.push((state){s.i,s.j,nf,nu});
            }   
        }
        rep(d,4){
            int ni = s.i+di[d], nj = s.j+dj[d];
            int f = (s.f+__builtin_popcount(sw[ni][nj]&s.used))%2;
            if(stage[f][ni][nj]>=0 and dist[ni][nj][s.f][s.used] < 0){
                dist[ni][nj][s.f][s.used] = dis+1;
                q.push((state){ni,nj,s.f,s.used});
            }
        }
    }
    return -1;
}

void input(){
    cin >> W >> H;
    string s;
    memset(stage,-1,sizeof(stage));
    rep(i,H){
        cin >> s;
        rep(j,W){
            if(s[j] == '%') si = i, sj = j, stage[0][i][j] = 11;
            else if(s[j] == '&') ti = i, tj = j, stage[0][i][j] = 11;
            else if(s[j] == '_') stage[0][i][j] = 11;
            else if(s[j] == '^') stage[1][i][j] = 11;
            else if(s[j] == '|') stage[0][i][j] = stage[1][i][j] = 10;
            else if('a' <= s[j] and s[j] <= 'j') stage[0][i][j] = s[j] - 'a';
            else if('A' <= s[j] and s[j] <= 'J') stage[1][i][j] = s[j] - 'A';
        }
    }
    cin >> S;
    rep(k,S) rep(i,H){
        cin >> s;
        rep(j,W) if(s[j] == '*') sw[i][j] |= 1<<k;
    }
}
int main(){
    input();
    cout << solve() << endl;
    return 0;
}


