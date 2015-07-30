#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i > (b); i--)
#define pb push_back
#define mp make_pair
#define INF 1e8
typedef vector<int> vi;
typedef pair<int,int> pii;

const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};
int w, h;
char field[25][25];

inline bool in(int i, int j){ return i>=0 && i<h && j>=0 && j<w;}

int make_path(pii a, pii b){
    bool visited[25][25] = {false};
    queue<pair<pii,int> > bfs;
    bfs.push(mp(a,0));
    visited[a.first][a.second] = true;
    while(!bfs.empty()){
        pii s = bfs.front().first;
        int turn = bfs.front().second;
        bfs.pop();
        if(s==b) return turn;
        int ti = s.first, tj = s.second;
        rep(i,4){
            int ni = ti + di[i], nj = tj + dj[i];
            if(in(ni,nj) && !visited[ni][nj] && field[ni][nj]!='x'){
                bfs.push(mp(mp(ni,nj),turn+1));
                visited[ni][nj] = true;
            }
        }
    }
    return -1;
}

int main(){
    while(cin>>w>>h,w||h){
        vector<pii> v;
        int start;
        rep(i,h)rep(j,w) cin>>field[i][j];
        rep(i,h)rep(j,w)if(field[i][j]=='o' || field[i][j]=='*'){
            v.pb(mp(i,j));
            if(field[i][j] == 'o') start = v.size()-1;
        }
        swap(v[0],v[start]);
        int t = v.size();
        vector<vi> path(t,vi(t,INF));
        bool flag = false;
        rep(i,t)repi(j,i,t){
            if(j==i){
                path[i][j] = 0;
                path[j][i] = 0;
                continue;
            }
            path[i][j] = make_path(v[i],v[j]);
            path[j][i] = path[i][j];
            if(path[i][j] == -1){
                cout << -1 << endl;
                flag = true;
                goto fail;
            }
        }
    fail:;
        if(flag) continue;
        vector<vi> dp(1<<t,vi(t,INF));
        rep(i,t) dp[(1<<t) - 1][i] = path[0][i];
        repd(i,(1<<t)-2,-1)rep(j,t)rep(k,t){
            if(!(i >> k & 1)){
                dp[i][j] = min(dp[i][j], dp[i | 1 << k][k] + path[j][k]);
            }
        }
        int ans = INF;
        rep(i,t) ans = min(ans, dp[1<<i][i]);
        cout << ans << endl;
    }
}
