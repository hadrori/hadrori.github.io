#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <bitset>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

#define INF 10000000

int x, y;
int field[64][64];
int dtx[4] = {1,0,-1,0};
int dkx[4] = {-1,0,1,0};
int dty[4] = {0,1,0,-1};
int dky[4] = {0,-1,0,1};

bool ok(int i, int j){
    if(i<x && j<y && i>=0 && j>=0 && !field[j][i]) return true;
    else return false;
}

struct S{
    int tx, ty, kx, ky, d;
    S(int tx, int ty, int kx, int ky, int d):tx(tx),ty(ty),kx(kx),ky(ky),d(d){}
};

int main(){

    while(cin>>x>>y,x||y){
        int ans = INF;
        int tx, ty, kx, ky;
        cin >> tx >> ty >> kx >> ky;
        tx--;
        ty--;
        kx--;
        ky--;

        rep(i,y)rep(j,x){
            cin >> field[i][j];
        }
        queue<S> bfs;
        bfs.push(S(tx,ty,kx,ky,0));
        int visited[64][64] = {0};
        visited[tx][ty] = 1;
        visited[kx][ky] = 1;

        while(!bfs.empty()){
            int atx = bfs.front().tx, aty = bfs.front().ty;
            int akx = bfs.front().kx, aky = bfs.front().ky;
            int td = bfs.front().d;
            visited[atx][aty] = td+1;
            visited[akx][aky] = td+1;
                
            bfs.pop();
            if(td == 100) continue;
            if(tx==kx && ty==ky){
                ans = min(ans,td);
                continue;
            }
            rep(i,4){
                int ttx = atx, tty = aty, tkx = akx, tky = aky;
                if(ok(tx+dtx[i],ty+dty[i])){
                    ttx += dtx[i];
                    tty += dty[i];
                }
                if(ok(kx+dkx[i],ky+dky[i])){
                    tkx += dkx[i];
                    tky += dky[i];
                }
                if(ttx == tx && tty == ty && tkx == kx && tky == ky) continue;
                if(visited[ttx][tty] != 0 && visited[ttx][tty] == visited[tkx][tky]) continue;
                bfs.push(S(ttx,tty,tkx,tky,td+1));
            }
        }
        cout << ans << endl;
    }
}
