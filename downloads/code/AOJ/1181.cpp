#include <bits/stdc++.h>
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define fst first
#define snd second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int offset = 128;

// f r b l
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

void rot(vi &dice, int dir){
    int tmp = dice[5];
    dice[5] = dice[(dir+2)%4]; dice[(dir+2)%4] = dice[4];
    dice[4] = dice[dir]; dice[dir] = tmp;
    return;
}

int main(){
    int n;
    while(cin >> n, n){
        pii field[256][256];
        int ans[7] = {0};
        rep(i,256)rep(j,256) field[i][j] = pii(0,0);
        while(n--){
            vi dice(4);
            int t, f; cin >> t >> f;
            dice[5] = t;
            dice[4] = 7 - t;
            dice[0] = f;
            dice[2] = 7 - f;
            if(t == 1){
                if(f == 2) dice[1] = 3;
                if(f == 3) dice[1] = 5;
                if(f == 5) dice[1] = 4;
                if(f == 4) dice[1] = 2;
            }
            if(t == 2){
                if(f == 1) dice[1] = 4;
                if(f == 4) dice[1] = 6;
                if(f == 6) dice[1] = 3;
                if(f == 3) dice[1] = 1;
            }
            if(t == 3){
                if(f == 1) dice[1] = 2;
                if(f == 2) dice[1] = 6;
                if(f == 6) dice[1] = 5;
                if(f == 5) dice[1] = 1;
            }
            if(t == 4){
                if(f == 1) dice[1] = 5;
                if(f == 5) dice[1] = 6;
                if(f == 6) dice[1] = 2;
                if(f == 2) dice[1] = 1;
            }
            if(t == 5){
                if(f == 1) dice[1] = 3;
                if(f == 3) dice[1] = 6;
                if(f == 6) dice[1] = 4;
                if(f == 4) dice[1] = 1;
            }
            if(t == 6){
                if(f == 2) dice[1] = 4;
                if(f == 4) dice[1] = 5;
                if(f == 5) dice[1] = 3;
                if(f == 3) dice[1] = 2;
            }
            dice[3] = 7 - dice[1];
            int x = 0 + offset, y = 0 + offset;
            while(true){
                int dir = -1, hight = field[x][y].fst, maxa = 0;
                rep(i,4){
                    if(dice[i] >= 4 && dice[i] > maxa && field[x+dx[i]][y+dy[i]].fst < hight) {
                        maxa = dice[i];
                        dir = i;
                    }
                }
                if(dir == -1)break;
                rot(dice, dir);
                x += dx[dir]; y += dy[dir];
            }
            ans[dice[5]]++;
            ans[field[x][y].snd]--;
            field[x][y].fst++;
            field[x][y].snd = dice[5];
        }
        repi(i,1,7) cout << ans[i] << (i==6? '\n': ' ');
    }
    return 0;
}
