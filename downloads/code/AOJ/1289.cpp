#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
const double eps = 1e-6;
struct point{
    double x, y, z;
    point(){}
    point(double x, double y, double z):x(x),y(y),z(z){}
    point& operator-=(const point &p){ x-=p.x;y-=p.y;z-=p.z; return *this;}
    point& operator+=(const point &p){ x+=p.x;y+=p.y;z+=p.z; return *this;}
    point& operator*=(double d){ x*=d;y*=d;z*=d; return *this;}
    point& operator/=(double d){ x/=d;y/=d;z/=d; return *this;}
};
point operator-(const point &p, const point &q){ point r(p); return r-=q;}
point operator+(const point &p, const point &q){ point r(p); return r+=q;}
point operator*(const point &p, double d){ point r(p); r*=d; return r;}
point operator*(double d, const point &p){ return p*d;}
point operator/(const point &p, double d){ point r(p); r/=d; return r;}
ostream& operator<<(ostream &o, const point &p){
    o << setprecision(10);
    o << p.x << " " << p.y << " " << p.z;
    return o;
}

struct sphere{
    point p; double r;
    sphere(point p, double r):p(p),r(r){}
};

struct line{
    point s, t;
    line(point s, point t):s(s),t(t){}
};

inline double dot(const point &a, const point &b){ return a.x*b.x+a.y*b.y+a.z*b.z;}
inline point cross(const point &a, const point &b) { return point(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);}
inline double norm(const point &p){ return p.x*p.x+p.y*p.y+p.z*p.z;}
inline double abs(const point &p){ return sqrt(norm(p));}
inline double abs(const line &l){ return abs(l.s-l.t);}

point projection(const line &l, const point &p) {
    double t = dot(p-l.s, l.s-l.t) / norm(l.s-l.t);
    return l.s+t*(l.s-l.t);
}

inline point reflection(const line &l, const point &p){ return p+2.0*(projection(l,p)-p);}

bool intersect(const sphere &s, const line &l){
    if(abs(l.t-s.p) < s.r-eps) return 1;
    point p = projection(l, s.p);
    return abs(p-l.s)+abs(p-l.t)-abs(l) < eps and abs(p-s.p)<s.r-eps;
}
point cross_point(const sphere &s, const line &l){
    point p = projection(l, s.p);
    double d = sqrt(s.r*s.r-norm(p-s.p));
    return p+(l.s-l.t)/abs(l)*d;
}

vector<sphere> S;
point u;
int N;

point solve(){
    line laz = line(point(0,0,0), u/abs(u)*500);
    int cur = -1;
    while(1){
        int nxt = -1;
        rep(i,N)if(i!=cur and intersect(S[i], laz)){
            laz.t = cross_point(S[i],laz);
            nxt = i;
        }
        if(nxt == -1) break;
        line mrr(S[nxt].p, laz.t);
        point r = reflection(mrr, laz.s);
        laz = line(laz.t, r+(r-laz.t)/abs(r-laz.t)*500);
        cur = nxt;
    }
    return laz.s;
}

bool input(){
    cin >> N;
    if(!N) return 0;
    S.clear();
    double x, y, z, r;
    cin >> x >> y >> z;
    u = point(x,y,z);
    rep(i,N) {
        cin >> x >> y >> z >> r;
        S.pb(sphere(point(x,y,z),r));
    }
    return 1;
}

int main(){
    while(input()) cout << solve() << endl;
    return 0;
}


