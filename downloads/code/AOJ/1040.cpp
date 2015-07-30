#include <algorithm>
#include <iostream>
#include <vector>

#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,a) repi(i,0,a)
#define INF 1e9
using namespace std;
typedef vector<int> vi;

int minimum_steiner_tree(const vector<int> &T, const vvi &g){
    const int n = g.size();
    const int t = T.size();
    if(t <= 1) return 0;
    vvi d(g);
    rep(k,n)rep(i,n)rep(j,n)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int OPT[1 << t][n];
    rep(S,1<<t) rep(x,n)
        OPT[S][x] = INF;
    rep(p,t) rep(q,n)
        OPT[1 << p][q] = d[T[p]][q];
    repi(S,1,1<<t){
        if(!(S & (S-1))) continue;
        rep(p,n) rep(E,S)
            if((E | S) == S)
                OPT[S][p] = min(OPT[S][p], OPT[E][p] + OPT[S-E][p]);
        rep(p,n) rep(q,n)
            OPT[S][p] = min(OPT[S][p], OPT[S][q] + d[p][q]);
    }
    
    int ans = INF;
    rep(S,1<<t) rep(q,n)
        ans = min(ans, OPT[S][q] + OPT[((1 << t) - 1) - S][q]);
    
    return ans;
}

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int h, w;

inline bool inrange(int x, int y){
    return x >= 0 && x < w && y >= 0 && y < h;
}
int main(){
    while(cin >> h >> w, h || w){
        vvi G(h*w, vi(h*w,INF));
        rep(i,h)rep(j,w){
            rep(k,4)if(inrange(j+dx[k], i+dy[k])){
                G[i*w+j][(i+dy[k])*w+j+dx[k]] = 1;
                G[(i+dy[k])*w+j+dx[k]][i*w+j] = 1;
            }
            G[i*w+j][i*w+j] = 0;
        }
        vi T;
        rep(i,h)rep(j,w){
            int t;
            cin >> t;
            if(t) T.pb(i*w+j);
        }
        cout << h*w - minimum_steiner_tree(T, G) - 1 << endl;
    }
    return 0;
}
