#include <bits/stdc++.h>
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
#define fst first
#define snd second
using namespace std;

int M, N;
vector<string> board;
int di[] = {-1,0,1,0};
int dj[] = {0,-1,0,1};

bool inrange(int i, int j){ return i >= 0 && i < M && j >= 0 && j < N;}

int check(){
    int ret = 0;
    rep(i,M)rep(j,N)if(board[i][j] == '.'){
        pii flag[32];
        rep(k,32) flag[k] = pii(-1,-1);
        rep(k,4){
            int ni = i, nj = j;
            while(inrange(ni,nj) && board[ni][nj] == '.'){
                ni += di[k]; nj += dj[k];
            }
            if(inrange(ni,nj)){
                int c = board[ni][nj] - 'A';
                if(flag[c].fst >= 0){
                    board[ni][nj] = '.';
                    board[flag[c].fst][flag[c].snd] = '.';
                    ret += 2;
                }
                else flag[c] = pii(ni,nj);
            }
        }
    }
    return ret;
}

int main(){
    cin >> M >> N;
    board.resize(M);
    rep(i,M) cin >> board[i];
    int ans = 0;
    int tmp;
    while(true){
        tmp = check();
        if(!tmp) break;
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}
