#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
const int di[] = {-1,0,1,0};
const int dj[] = {0,1,0,-1};
struct node{
    int i, j, p, q, dir, dis;
    bool operator<(const node &n) const{ return dis > n.dis;}
};
int N, M, A, si, sj, ti, tj;
bool room[128][128];
int dist[101][101][11][11][4];
inline bool in(int i, int j){ return i >= 0 and j >= 0 and i < N and j < M;}

int solve(){
    memset(dist,-1,sizeof(dist));
    priority_queue<node> que;
    que.push((node){si,sj,0,0,2,0});
    while(!que.empty()){
        node v = que.top(); que.pop();
        if(v.i == ti and v.j == tj) return v.dis;
        if(dist[v.i][v.j][v.p][v.q][v.dir] >= 0) continue;
        dist[v.i][v.j][v.p][v.q][v.dir] = v.dis;
        rep(nd,3){
            int d = (v.dir+nd+3)%4;
            if(v.i == si and v.j == sj and v.dis and di[d]) continue;
            if(v.i == si and v.j == sj and v.dir != d) continue;
            bool isp = (v.dir+d)==3;
            bool isq = (v.dir+d)%4==1;            
            if(isp and v.p >= A) continue;
            if(isq and v.q >= A) continue;
            int i = v.i+di[d], j = v.j+dj[d];
            if(in(i,j) and room[i][j])
                que.push((node){i,j,v.p+isp,v.q+isq,d,v.dis+isp+isq});
        }
    }
    return -1;
}

void input(){
    cin >> N >> M >> A;
    rep(i,N) rep(j,M){
        char c; cin >> c;
        room[i][j] = 1;
        if(c == 'S') si = i, sj = j;
        else if(c == 'G') ti = i, tj = j;
        else if(c == '#') room[i][j] = 0;
    }
}
signed main(){
    input();
    cout << solve() << endl;
    return 0;
}


