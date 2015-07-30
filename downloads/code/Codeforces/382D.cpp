#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
const int MAX = 2001;
typedef pair<int,int> pii;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
const string dir = "v>^<";

char b[MAX][MAX];
int H, W, done;
inline bool in(int i, int j){ return i>=0 and i<H and j>=0 and j<W;}

int dfs(int i, int j, int dep){
    done++;
    int ret = dep;
    rep(d,4){
        int ni = i + di[d], nj = j + dj[d];
        if(in(ni,nj) and b[ni][nj] == dir[d])
            ret = max(ret, dfs(ni,nj,dep+1));
    }
    return ret;
}

int solve(){
    int u = 0, v = 0;
    rep(i,H)rep(j,W)
        if(b[i][j] == '#'){
            done++;
            rep(d,4){
                int ni = i + di[d], nj = j + dj[d];
                if(in(ni,nj) and b[ni][nj] == dir[d]){
                    int t = dfs(ni,nj,1);
                    if(u < t) u = t, v = t-1;
                    else if(v < t) v = t;
                }
            }
        }
    return done<H*W? -1: u + v;
}

void input(){
    cin >> H >> W;
    rep(i,H)rep(j,W) cin >> b[i][j];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
