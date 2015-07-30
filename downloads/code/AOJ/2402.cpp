#include <bits/stdc++.h>
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)
using namespace std;
typedef vector<int> vi;
typedef complex<double> P;

inline double dot(const P& a, const P& b){ return real(conj(a)*b);}
inline double cross(const P& a, const P& b) { return imag(conj(a)*b);}

struct L {
    P a, b;
    L(const P &a, const P &b) : a(a), b(b){}
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

P projection(const L &l, const P &p) {
    double t = dot(p-l.a, l.a-l.b) / norm(l.a-l.b);
    return l.a + t*(l.a-l.b);
}

bool intersectSS(const L &s, const L &t) {
    return ccw(s.a,s.b,t.a)*ccw(s.a,s.b,t.b) <= 0 &&
        ccw(t.a,t.b,s.a)*ccw(t.a,t.b,s.b) <= 0;
}
bool intersectSP(const L &s, const P &p) {
    return abs(s.a-p)+abs(s.b-p)-abs(s.b-s.a) < EPS; // 三角不等式
}

double distanceSP(const L &s, const P &p){
    const P r = projection(s, p);
    if (intersectSP(s, r)) return abs(r - p);
    return min(abs(s.a - p), abs(s.b - p));
}
double distanceSS(const L &s, const L &t){
    if (intersectSS(s, t)) return 0;
    return min(min(distanceSP(s, t.a), distanceSP(s, t.b)),
               min(distanceSP(t, s.a), distanceSP(t, s.b)));
}

int n, m, l;

struct S{
    vector<L> li;
    S(int x, int y, int a, int r){
        double theta = PI * a / 180;
        vector<P> p;
        rep(i,5){
            double dx = r * sin(theta + PI * 72 / 180 * i);
            double dy = r * cos(theta + PI * 72 / 180 * i);
            p.pb(P(x - dx, y + dy));
        }
        li.pb(L(p[0], p[2]));
        li.pb(L(p[0], p[3]));
        li.pb(L(p[1], p[3]));
        li.pb(L(p[1], p[4]));
        li.pb(L(p[2], p[4]));
    }
};

typedef pair<double,int> pdi;

int main(){
    while(cin >> n >> m >> l, n || m || l){
        m--; l--;
        vector<S> star;
        rep(i,n){
            int x, y, a, r;
            cin >> x >> y >> a >> r;
            star.pb(S(x,y,a,r));
        }
        double path[128][128];
        rep(i,128)rep(j,128) path[i][j] = INF;
        rep(i,n)repi(j,i+1,n){
            double dist = INF;
            rep(a,5)rep(b,5){
                dist = min(dist,
                           distanceSS(star[i].li[a], star[j].li[b]));
            }
            path[i][j] = dist;
            path[j][i] = dist;
        }
        priority_queue<pdi,vector<pdi>,greater<pdi> > que;
        bool visited[128] = {false};
        double d[128];
        rep(i,128) d[i] = INF;
        d[m] = 0;
        que.push(mp(0,m));
        while(!que.empty()){
            pdi p = que.top(); que.pop();
            if(p.second == l) break;
            if(visited[p.second]) continue;
            visited[p.second] = true;
            rep(i,n){
                if(d[i] > path[p.second][i] + p.first){
                    d[i] = path[p.second][i] + p.first;
                    que.push(mp(d[i],i));
                }
            }
        }
        printf("%.8f\n",d[l]);
    }
}
