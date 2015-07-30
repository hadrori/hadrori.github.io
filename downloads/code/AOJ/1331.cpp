#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
const int inf = 1e9;
const double eps = 1e-9;
struct point{
    double x, y, z;
    point():x(0),y(0),z(0){}
    point(double x, double y, double z):x(x),y(y),z(z){}
    point operator+(const point &p) const{ return point(x+p.x, y+p.y, z+p.z);}
    point operator-(const point &p) const{ return point(x-p.x, y-p.y, z-p.z);}
    point operator*(const double &d) const{ return point(x*d, y*d, z*d);}
    point operator/(const double &d) const{ return point(x/d, y/d, z/d);}
};
struct sphere{
    point p; double r;
    sphere(point p, double r):p(p),r(r){}
};
struct line{
    point a, b;
    line(point a, point b):a(a),b(b){}
};
int N, M, R;
point obj;
vector<sphere> bal;
vector<point> src;
vector<int> rmv[16];
double br[16];

inline double norm(const point &a){ return a.x*a.x+a.y*a.y+a.z*a.z;}
inline double abs(const point &a){ return sqrt(norm(a));}
inline double dot(const point &a, const point &b){ return a.x*b.x+a.y*b.y+a.z*b.z;}
point proj(const line &l, const point &p){
    double t = dot(p-l.a, l.a-l.b) / norm(l.a-l.b);
    return l.a+(l.a-l.b)*t;
}
bool intersect(const line &l, const sphere &s){
    point a = l.a-s.p, b = l.b-s.p, c = proj(l,s.p)-s.p;
    if(abs(a) < s.r-eps and abs(b) < s.r-eps and abs(c) < s.r-eps) return 0; // contain
    if(abs(c) > s.r+eps) return 0; // far
    if(abs(a) < s.r-eps or abs(b) < s.r-eps) return 1; // intersect
    if(abs(a-c)+abs(b-c)<abs(a-b)+eps) return 1; // intersect
    return 0;
}

double solve(){
    rep(i,M) rmv[i].clear();
    rep(i,M)rep(j,N)
        if(intersect(line(src[i],obj), bal[j])) rmv[i].pb(j);
    double ans = 0.;
    rep(S,1<<M){
        bool rm[2048] = {};
        int cnt = 0; double sum = 0.;
        rep(i,M)if((S>>i)&1){
            rep(j,rmv[i].size()) if(!rm[rmv[i][j]]){
                rm[rmv[i][j]] = 1;
                cnt++;
            }
            sum += br[i]/norm(src[i]-obj);
        }
        if(cnt <= R) ans = max(ans, sum);
    }
    return ans;
}

bool input(){
    cin >> N >> M >> R;
    if(!N and !M and !R) return 0;
    int x, y, z, r;
    bal.clear(); src.clear();
    rep(i,N){
        cin >> x >> y >> z >> r;
        bal.pb(sphere(point(x,y,z),r));
    }
    rep(i,M){
        cin >> x >> y >> z >> r;
        src.pb(point(x,y,z));
        br[i] = r;
    }
    cin >> x >> y >> z;
    obj = point(x,y,z);
    return 1;
}
int main(){
    while(input()) printf("%.8f\n", solve());
    return 0;
}


