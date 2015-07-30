#include <bits/stdc++.h>
#define rep(i,a) for(int i = 0;i < (a); i++)
#define INF 1e9
using namespace std;
typedef vector<int> vi;

int w, h;
int di[] = {0,1,0,-1};
int dj[] = {1,0,-1,0};

struct S{
    int i, j, st, dis;
    S(int i, int j, int st, int dis):i(i),j(j),st(st),dis(dis){}
    bool operator > (const S &s) const{
        return dis > s.dis;
    }
};

bool inrange(int i, int j){
    return (i<h && i>=0 && j<w && j>=0);
}

int main(){
    while(cin>>w>>h,w||h){
        int field[h][w];
        int c[4];
        rep(i,h)rep(j,w) cin >> field[i][j];
        rep(i,4) cin >> c[i];
        vector<vector<vector<vi> > > path(h,vector<vector<vi> >(w,vector<vi>(4,vi(4,INF))));
        rep(i,h)rep(j,w){
            int com = field[i][j];
            rep(k,4){
                switch(com){
                case 0:
                    if(inrange(i+di[k],j+dj[k])) path[i][j][k][k] = 0;
                    if(inrange(i+di[(k+1)%4],j+dj[(k+1)%4])) path[i][j][k][(k+1)%4] = c[1];
                    if(inrange(i+di[(k+2)%4],j+dj[(k+2)%4])) path[i][j][k][(k+2)%4] = c[2];
                    if(inrange(i+di[(k+3)%4],j+dj[(k+3)%4])) path[i][j][k][(k+3)%4] = c[3];
                    break;
                case 1:
                    if(inrange(i+di[k],j+dj[k])) path[i][j][k][k] = c[0];
                    if(inrange(i+di[(k+1)%4],j+dj[(k+1)%4])) path[i][j][k][(k+1)%4] = 0;
                    if(inrange(i+di[(k+2)%4],j+dj[(k+2)%4])) path[i][j][k][(k+2)%4] = c[2];
                    if(inrange(i+di[(k+3)%4],j+dj[(k+3)%4])) path[i][j][k][(k+3)%4] = c[3];
                    break;
                case 2:
                    if(inrange(i+di[k],j+dj[k])) path[i][j][k][k] = c[0];
                    if(inrange(i+di[(k+1)%4],j+dj[(k+1)%4])) path[i][j][k][(k+1)%4] = c[1];
                    if(inrange(i+di[(k+2)%4],j+dj[(k+2)%4])) path[i][j][k][(k+2)%4] = 0;
                    if(inrange(i+di[(k+3)%4],j+dj[(k+3)%4])) path[i][j][k][(k+3)%4] = c[3];
                    break;
                case 3:
                    if(inrange(i+di[k],j+dj[k])) path[i][j][k][k] = c[0];
                    if(inrange(i+di[(k+1)%4],j+dj[(k+1)%4])) path[i][j][k][(k+1)%4] = c[1];
                    if(inrange(i+di[(k+2)%4],j+dj[(k+2)%4])) path[i][j][k][(k+2)%4] = c[2];
                    if(inrange(i+di[(k+3)%4],j+dj[(k+3)%4])) path[i][j][k][(k+3)%4] = 0;
                    break;
                case 4:
                    if(inrange(i+di[k],j+dj[k])) path[i][j][k][k] = c[0];
                    if(inrange(i+di[(k+1)%4],j+dj[(k+1)%4])) path[i][j][k][(k+1)%4] = c[1];
                    if(inrange(i+di[(k+2)%4],j+dj[(k+2)%4])) path[i][j][k][(k+2)%4] = c[2];
                    if(inrange(i+di[(k+3)%4],j+dj[(k+3)%4])) path[i][j][k][(k+3)%4] = c[3];
                    break;
                }
            }
        }
        vector<vector<vi> > d(h,vector<vi>(w,vi(4,INF)));
        d[0][0][0] = 0;
        priority_queue<S, vector<S>, greater<S> > que;
        que.push(S(0,0,0,0));
        while(!que.empty()){
            S s = que.top(); que.pop();
            int ti = s.i, tj = s.j, st = s.st, dis = s.dis;
            rep(k,4){
                int ni = ti+di[k], nj = tj+dj[k];
                if(inrange(ni,nj)){
                    if(d[ni][nj][k] > d[ti][tj][st] + path[ti][tj][st][k]){
                        d[ni][nj][k] = d[ti][tj][st] + path[ti][tj][st][k];
                        que.push(S(ni,nj,k,d[ni][nj][k]));
                    }
                }
            }
        }
        int ans = INF;
        rep(i,4) ans = min(ans, d[h-1][w-1][i]);
        cout << ans << endl;
    }
}
