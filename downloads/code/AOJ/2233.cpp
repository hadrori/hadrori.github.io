#include <bits/stdc++.h>
#define rep(i,a) for(int i = 0;i < (a); i++)
#define pb push_back
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)
using namespace std;
typedef complex<double> P;
typedef vector<P> G;

int n;
double r, th;
G city;
vi path[32][32];
double memo[32][32][10010];

bool ok(int i, int j, int k){
    double rad = abs(arg((city[j] - city[i]) / (city[k] - city[j])));
    return rad < th + EPS;
}

struct S{
    int prev, cur, have;
    double dist;
    S(int prev, int cur, int have, double dist):
        prev(prev),cur(cur),have(have),dist(dist){}
    bool operator < (const S &s) const { return dist > s.dist;}
};

int main(){
    cin >> n >> r >> th;
    th *= PI / 180;
    city.resize(n);
    rep(i,n) cin >> city[i].real() >> city[i].imag();
    rep(i,n)rep(j,n)rep(k,n)
        if(i!=j && j!=k && ok(i,j,k))
            path[i][j].pb(k);
    
    rep(i,n)rep(j,n)rep(k,10010) memo[i][j][k] = INF;
    
    priority_queue<S> que;
    rep(i,n-1)if(abs(city[0]-city[i+1]) < r + EPS){
        que.push(S(0,i+1,1,abs(city[0]-city[i+1])));
        memo[0][i+1][1] = abs(city[0]-city[i+1]);
    }
    
    int ans = 0;
    while(!que.empty()){
        S s = que.top(); que.pop();
        int p = s.prev, c = s.cur, h = s.have;
        double d = s.dist;
        bool exist = false;

        if(d > memo[p][c][h]) continue;
        memo[p][c][h] = d;
        rep(i,path[p][c].size()){
            int nc = path[p][c][i];
            double dis = abs(city[c]-city[nc]) + d;
            if(dis < r + EPS && memo[c][nc][h+1] > dis){
                que.push(S(c, nc, h+1, dis));
                memo[c][nc][h+1] = dis;
                exist = true;
            }
        }
        if(!exist) ans = max(ans, h);
    }
    cout << ans << endl;
    return 0;
}
