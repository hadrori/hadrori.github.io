#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
const int inf = 1e9;
const long double eps = 1e-10;
struct runner{
    long double p; int t, v;
    runner(long double p, int t, int v):p(p),t(t),v(v){}
};
int N, M, L;
long double ps[128][64][64];
long double sc[128][64];
long double ans[128];
vector<runner> r;

void input(){
    r.clear();
    cin >> N >> M >> L;
    rep(i,N){
        int p, t, v;
        cin >> p >> t >> v;
        r.pb(runner(p/100., t, v));
    }
}

void solve(){
    rep(i,N) {
        ps[i][0][0] = 1.;
        rep(j,M+1) {
            if(j < M) rep(k, j+1){
                ps[i][j+1][k+1] += ps[i][j][k]*r[i].p;
                ps[i][j+1][k] += ps[i][j][k]*(1.-r[i].p);
            }
            if(r[i].v == 0) sc[i][j] = inf;
            else sc[i][j] = 1.*L/r[i].v + j*r[i].t;
        }
    }
    rep(i,N) {
        ans[i] = 0.;
        if(r[i].v == 0) continue;
        rep(a,M+1){ 
            long double p = ps[i][M][a];
            rep(j,N) if(j != i){
                long double q = 0.;
                rep(b,M+1) if(sc[i][a] < sc[j][b]-eps) q += ps[j][M][b];
                p *= q;
            }
            ans[i] += p;
        }
    }
    rep(i,N) printf("%.10Lf\n", ans[i]);
}

signed main(){
    input();
    solve();
    return 0;
}


