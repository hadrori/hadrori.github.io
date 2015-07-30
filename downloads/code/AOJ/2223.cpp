#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
int H, W, cnt;
char table[16][16];
const string dir = "URDL";
const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
inline bool in(int i, int j) { return i >= 0 and i < H and j >= 0 and j < W;}
string ans = "";

bool rec(int i, int j, int d, int res){
    table[i][j] = '.';
    if(!res) return 1;
    rep(k,3){
        int nd = (d+k+3)%4;
        int ni = i, nj = j;
        ans.pb(dir[nd]);
        while(in(ni,nj) and table[ni][nj] == '.')
            ni += di[nd], nj += dj[nd];
        if(in(ni,nj) and rec(ni,nj,nd,res-1)) return 1;
        ans.erase(ans.size()-1);
    }
    table[i][j] = 'o';
    return 0;
}
string solve(){
    rep(i,H)rep(j,W)
        if(dir.find(table[i][j]) != string::npos){
            rec(i,j,dir.find(table[i][j]),cnt);
            return ans;
        }
    return "";
}

void input(){
    cin >> H >> W;
    rep(i,H) rep(j,W){
        cin >> table[i][j];
        if(table[i][j] == 'o') cnt++;
    }
}
signed main(){
    input();
    cout << solve() << endl;
    return 0;
}


