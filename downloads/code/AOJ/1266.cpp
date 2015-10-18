#include <bits/stdc++.h>
namespace D3 {
const double eps = 1e-8;
 
struct point {
    double x, y, z;
    point(){}
    point(double x, double y, double z) : x(x), y(y), z(z) {}
    double norm() const { return x*x+y*y+z*z; }
    double abs() const { return std::sqrt(norm()); }
    double dot(const point &p) const { return x*p.x+y*p.y+z*p.z; }
    point cross(const point &p) const { return point(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x); }
 
    point operator*=(const double &k) { x*=k;y*=k;z*=k; return (*this); }
    point operator*(const double &k) const { return point(*this)*=k; }
    point operator+=(const point &p) { x+=p.x;y+=p.y;z+=p.z; return (*this); }
    point operator+(const point &p) const { return point(*this)+=p; }
    point operator-=(const point &p) { x-=p.x;y-=p.y;z-=p.z; return (*this); }
    point operator-(const point &p) const { return point(*this)-=p; }
};
std::ostream &operator<<(std::ostream &o, const point &p) { o << '(' << p.x << ',' << p.y << ',' << p.z << ')'; return o; }
}
using namespace D3;
using namespace std;
 
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)
 
int n, m, can[512];
vector<point> ps, ss;
double args[64];
 
bool observable(point p, point q, double a) {
    return acos(p.dot(q)/p.abs()/q.abs()) < a+eps;
}
 
int solve() {
    memset(can,0,sizeof(can));
    rep(i,m) rep(j,n) can[j] |= observable(ss[i],ps[j],args[i]);
    return accumulate(can,can+n,0);
}
 
point inp() {
    double x, y, z;
    cin >> x >> y >> z;
    return point(x,y,z);
}
 
bool input() {
    cin >> n;
    if(!n) return 0;
    ss.clear();
    ps.clear();
    rep(i,n) ps.push_back(inp());
    cin >> m;
    rep(i,m) {
        ss.push_back(inp());
        cin >> args[i];
    }
    return 1;
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    for(int t = 0; input(); t++) {
        cout << solve() << endl;
    }
    return 0;
}
