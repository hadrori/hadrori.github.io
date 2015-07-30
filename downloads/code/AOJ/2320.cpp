#include <bits/stdc++.h>
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
using namespace std;
typedef long long ll;

int H, W;
ll L;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
bool inrange(int x, int y){ return x >= 0 && x < W && y >= 0 && y < H;}

int main(){
    while(cin >> H >> W >> L, H || W || L){
        vector<string> maze(H);
        rep(i,H) cin >> maze[i];
        int x, y, dir;
        rep(i,H)rep(j,W){
            if(maze[i][j] == 'W'){ dir = 0; x = j; y = i; break;}
            else if(maze[i][j] == 'N'){ dir = 1; x = j; y = i; break;}
            else if(maze[i][j] == 'E'){ dir = 2; x = j; y = i; break;}
            else if(maze[i][j] == 'S'){ dir = 3; x = j; y = i; break;}
        }
        int field[128][128][4];
        memset(field,-1,sizeof(field));
        field[y][x][dir] = 0;
        ll turn = 1;
        bool rooped = false;
        while(turn <= L){
            int nx, ny, ndir;
            rep(i,4){
                ndir = (dir+i)%4;
                nx = x + dx[ndir];
                ny = y + dy[ndir];
                if(inrange(nx, ny) && maze[ny][nx] != '#'){
                    x = nx; y = ny; dir = ndir;
                    break;
                }
            }
            if(!rooped && field[y][x][dir] >= 0){
                rooped = true;
                ll roop = turn - field[y][x][dir];
                turn += (L - turn) / roop * roop;
                turn++;
            }
            else{
                field[y][x][dir] = turn;
                turn++;
            }
        }
        cout << y+1 << ' ' << x+1 << ' ';
        cout << (dir==0? 'W': dir==1? 'N': dir==2? 'E': 'S') << endl;
    }
    return 0;
}
