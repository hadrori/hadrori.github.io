#include <iostream>
#include <vector>
#include <string>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

int n;

bool inrange(int x, int y, int z){
    return (x>0 && x<=n && y>0 && y<=n && z>=0 && z<n);
}

int dx[13] = { 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
int dy[13] = { 0, 1, 0, 1, 1, 0, 0, 1,-1, 1, 1,-1,-1};
int dz[13] = { 0, 0, 1, 1,-1, 1,-1, 0, 0, 1,-1, 1,-1};

int main(){
    int  m, p;
    while(cin>>n>>m>>p,n||m||p){
        vector<mat> field(n+1,mat(n+1,(vec(n+1,0))));
        bool ok = true;
        string winner;
        int turn;

        rep(i,p){
            int x, y;
            cin >> x >> y;
            if(ok){
                int st = i % 2 + 1;
                int z = 0;
                while(inrange(x,y,z) && field[x][y][z])z++;

                field[x][y][z] = st;
                rep(j,13){
                    int tx = x, ty = y, tz = z;
                    int cnt = 0;
                    while(inrange(tx,ty,tz) && field[tx][ty][tz] == st){
                        cnt++;
                        tx += dx[j];
                        ty += dy[j];
                        tz += dz[j];
                    }
                    tx = x - dx[j];
                    ty = y - dy[j];
                    tz = z - dz[j];
                    while(inrange(tx,ty,tz) && field[tx][ty][tz] == st){
                        cnt++;
                        tx -= dx[j];
                        ty -= dy[j];
                        tz -= dz[j];
                    }
                    if(cnt >= m){
                        winner = (st==1)? "Black ": "White ";
                        turn = i + 1;
                        ok = false;
                        break;
                    }
                }
            }
        }
        if(ok) cout << "Draw\n";
        else cout << winner << turn << endl; 
    }
}
