#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define pb push_back
#define mp make_pair
#define INF 1e9
#define PI acos(-1.0)
typedef pair<int,int> pii;
typedef complex<double> P;

inline double dot(const P& a, const P& b) { return real(conj(a)*b);}
inline double cross(const P& a, const P& b) { return imag(conj(a)*b);}

struct L {
    P a, b;
    L(const P &a, const P &b) : a(a), b(b){ }
};

struct C {
    P p; double r;
    C() : p(0), r(0) {}
    C(const P &p, double r) : p(p), r(r) { }
};

/* 点の進行方向 (a->b->c) */
int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // +1 : 反時計回り
    if (cross(b, c) < 0)   return -1;       // -1 : 時計回り
    if (dot(b, c) < 0)     return +2;       // +2 : 線上(c--a--b)
    if (norm(b) < norm(c)) return -2;       // -2 : 線上(a--b--c)
    return 0;
}

L crosspointCC(const C &c1, const C &c2){ // 重なっているとnan
    double d = abs(c1.p - c2.p);
    double x = (c1.r*c1.r - c2.r*c2.r + d*d) / (2.0*d);
    P v = sqrt(c1.r*c1.r - x*x)*(c1.p-c2.p)/abs(c1.p-c2.p)*P(0, 1);
    P h = c1.p + x * (c2.p - c1.p)/abs(c2.p - c1.p);
    return L(h - v, h + v);
}

int n;

struct Circle{
    C c;
    P lp, rp;
    Circle(C c, P lp, P rp):c(c),lp(lp),rp(rp){}
};

typedef pair<double,pii> pdpii;

int main(){
    while(cin >> n, n){
        vector<Circle> chain;
        rep(i,n){
            int x, y, r;
            cin >> x >> y >> r;
            C c = C(P(x, y), r);
            if(i == 0){
                chain.pb(Circle(c, P(x,y), P(x,y)));
                continue;
            }
            L l = crosspointCC(c, chain[i-1].c);
            if(ccw(chain[i-1].c.p, c.p, l.a) == 1)
                chain.pb(Circle(c, l.a, l.b));
            else chain.pb(Circle(c, l.b, l.a));
        }
        double path[128][128][2][2];
        rep(i,128)rep(j,128)rep(k,2)rep(l,2) path[i][j][k][l] = INF;
        rep(i,n)rep(k,2){
            P p = (i == 0)? chain[i].c.p
                : (k == 0)? chain[i].lp
                : chain[i].rp;
            repi(j,i+1,n+1){
                if(j == n){
                    bool ok = true;
                    repi(a,i,n){
                        if(ccw(p, chain[n-1].c.p, chain[a].lp) == -1 ||
                           ccw(p, chain[n-1].c.p, chain[a].rp) == 1 ){
                            ok = false;
                            break;
                        }
                    }
                    if(ok) path[i][n][k][0] = abs(p-chain[n-1].c.p);
                    continue;
                }
                bool ok = true;
                repi(a,i,j){
                    if(ccw(p, chain[j].lp, chain[a].lp) == -1 ||
                       ccw(p, chain[j].lp, chain[a].rp) == 1 ){
                        ok = false;
                        break;
                    }
                }
                if(ok) path[i][j][k][0] = abs(p-chain[j].lp);

                ok = true;
                repi(a,i,j){
                    if(ccw(p, chain[j].rp, chain[a].lp) == -1 ||
                       ccw(p, chain[j].rp, chain[a].rp) == 1 ){
                        ok = false;
                        break;
                    }
                }
                if(ok) path[i][j][k][1] = abs(p-chain[j].rp);
            }
        }
        path[n-1][n][0][0] = chain[n-1].c.r;
        path[n-1][n][1][0] = chain[n-1].c.r;
        double d[128][2];
        bool visited[128][2] = {false};
        rep(i,128)rep(j,2) d[i][j] = INF;
        priority_queue<pdpii, vector<pdpii>, greater<pdpii> > que;
        que.push(mp(0, mp(0,0)));
        d[0][0] = d[0][1] = 0;
        while(!que.empty()){
            pdpii p = que.top(); que.pop();
            int cir = p.second.first, lr = p.second.second;
            double dist = p.first;
            if(visited[cir][lr]) continue;
            visited[cir][lr] = true;
            rep(i,n+1)rep(j,2)if(d[i][j] > dist + path[cir][i][lr][j]){
                d[i][j] = dist + path[cir][i][lr][j];
                que.push(mp(d[i][j], mp(i,j)));
            }
        }
        printf("%.8f\n", d[n][0]);
    }
}
