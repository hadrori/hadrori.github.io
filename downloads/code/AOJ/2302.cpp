#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back

typedef pair<int,int> pii;
const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};
int R, C, M, t;
bool room[64][64], checked[64][64];
int cst[4][64][64];
pii task[1024];
vector<int> visit[64][64];

inline bool in(int &r, int &c){ return r >= 0 and r < R and c >= 0 and c < C;}

int dfs(int r, int c, int i, int d){
    if(r == task[i].first and c == task[i].second){
        return d;
    }
    rep(k,4){
        int nr = r + dr[k], nc = c + dc[k];
        if(in(nr,nc) and room[nr][nc] and !checked[nr][nc]){
            checked[nr][nc] = 1;
            int ret = dfs(nr,nc,i,d+1);
            checked[nr][nc] = 0;
            if(ret){
                visit[r][c].pb(t+d);
                return ret;
            }
        }
    }
    return 0;
}

int solve(){
    int r = task[0].first, c = task[0].second;
    t = 0;
    repi(i,1,M){
        checked[r][c] = 1;
        int d = dfs(r,c,i,0);
        checked[r][c] = 0;
        r = task[i].first;
        c = task[i].second;
        t += d;
    }
    visit[r][c].pb(t);
    int ans = 0;
    rep(r,R)rep(c,C) if(room[r][c]){
        vector<int> &v = visit[r][c];
        if(visit[r][c].size() == 0) continue;
        ans += cst[1][r][c] + cst[2][r][c]; // first in last out
        rep(i,v.size()-1){
            if((v[i+1]-v[i])*cst[0][r][c] > cst[1][r][c] + cst[2][r][c])
                ans += cst[1][r][c] + cst[2][r][c];
            else ans += (v[i+1]-v[i]) * cst[0][r][c];
        }
    }
    return ans;
}

void input(){
    cin >> R >> C >> M;
    rep(i,R)rep(j,C){
        char c; cin >> c;
        room[i][j] = (c == '.');
    }
    rep(k,3)rep(i,R)rep(j,C) cin >> cst[k][i][j];
    rep(i,M) cin >> task[i].first >> task[i].second;
}
int main(){
    input();
    cout << solve() << endl;
    return 0;
}


