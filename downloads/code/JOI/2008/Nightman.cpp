#include <bits/stdc++.h>
namespace D2
{
const double eps = 1e-8;
bool eq(const double &a, const double &b) { return std::abs(a-b)<eps;}

struct point
{
        double x, y;
        point():x(0),y(0){}
        point(double x, double y):x(x),y(y){}

        point operator+=(const point &p){ x+=p.x; y+=p.y; return *this;}
        point operator-=(const point &p){ x-=p.x; y-=p.y; return *this;}
        point operator*=(const double &d){ x*=d; y*=d; return *this;}
        point operator/=(const double &d){ x/=d; y/=d; return *this;}
        point operator+(const point &p) const { return point(*this)+=p;}
        point operator-(const point &p) const { return point(*this)-=p;}
        point operator*(const double &d) const { return point(*this)*=d;}
        point operator/(const double &d) const { return point(*this)/=d;}
        point operator-()const{ return point(-x,-y);}
        bool operator<(const point &p) const { return std::abs(x- p.x)>eps ? x < p.x-eps : y < p.y-eps;}
        bool operator==(const point &p) const { return std::abs(x-p.x)<eps and std::abs(y-p.y)<eps;}
        bool operator!=(const point &p) const { return !(point(*this)==p);}

        double norm() const { return x*x+y*y;}
        double abs() const { return sqrt(norm());}
        double arg() const { return atan2(y, x);}
        double dot(const point &p) const { return x*p.x+y*p.y;}
        double cross(const point &p) const { return x*p.y-y*p.x;}
        double det(const point &p) const { return x*p.y-y*p.x;}
};

std::ostream &operator<<(std::ostream &os, const point &p) { os << "(" << p.x << "," << p.y << ")"; return os; }


int ccw(point a, point b, point c)
{
        b -= a, c -= a;
        if (b.det(c) > eps) return +1;
        if (b.det(c) < eps) return -1;
        if (b.dot(c) < eps) return +2;
        if (b.norm() < c.norm()-eps) return -2;
        return 0;
}

struct line
{
        point a, b;
        line(){}
        line(point a, point b):a(a),b(b){}

        point vec() const { return b-a;}
        double abs() const { return vec().abs();}
        double norm() const { return vec().norm();}
};

std::ostream &operator<<(std::ostream &os, const line &l) { os << l.a << "-" << l.b; return os; }

inline bool ils(const line &l, const line &s){ return ccw(l.a,l.b,s.a)*ccw(l.a,l.b,s.b)<=0;}
inline bool iss(const line &s, const line &t){ return ils(s,t) and ils(t,s);}

}

using namespace std;
using namespace D2;
const double inf = 1e9;
typedef pair<int,int> pii;
typedef pair<double,int> pdi;

struct rect
{
        point v[4];
        rect(point p, point q){
                double e = eps*100;
                v[0] = point(p.x+e, p.y+e);
                v[1] = point(q.x-e, p.y+e);
                v[2] = point(q.x-e, q.y-e);
                v[3] = point(p.x+e, q.y-e);
        }
};

int a, b, c, w, h, n;
vector<int> G[1024];
vector<rect> bl;
vector<point> ps;

bool intersect(point p, point q, rect r)
{
        line s = line(p,q);
        for (int i = 0; i < 4; i++) {
                line t = line(r.v[i],r.v[(i+1)%4]);
                if(iss(s,t)) return 1;
        }

        return 0;
}

void build_graph()
{
        n = ps.size();
        for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                        bool f = 1;
                        for(auto &r: bl) {
                                if(!intersect(ps[i],ps[j],r)) continue;
                                f = 0;
                                break;
                        }
                        if(f) {
                                G[i].push_back(j);
                                G[j].push_back(i);
                        }
                }
        }
}

double dist[1024];
double dijkstra(int s, int t)
{
        fill(dist,dist+n,inf);
        priority_queue<pdi, vector<pdi>, greater<pdi>> q;
        q.push(pdi(0,s));
        while(!q.empty()) {
                double d = q.top().first;
                int v = q.top().second;
                q.pop();
                if(dist[v] < d+eps) continue;
                dist[v] = d;
                if(v == t) return d;
                for(auto &e: G[v]) q.push(pdi(d+(ps[v]-ps[e]).abs(),e));
        }
        return inf;
}

double solve()
{
        build_graph();

        double ans = 0;
        for (int i = 0; i < c; i++) {
                double tmp = inf;
                for (int j = 0; j < a; j++)
                        tmp = min(tmp, dijkstra(j,a+4*b+i));
                ans += tmp*2;
        }
        return ans;
}

void input()
{
        cin >> a >> b >> c;
        cin >> w >> h;
        for (int i = 0; i < a; i++) {
                int x, y;
                cin >> x >> y;
                ps.push_back(point(x,y));
        }
        for (int i = 0; i < b; i++) {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                bl.push_back(rect(point(x1,y1),point(x2,y2)));
                ps.push_back(point(x1,y1));
                ps.push_back(point(x2,y1));
                ps.push_back(point(x2,y2));
                ps.push_back(point(x1,y2));
        }
        for (int i = 0; i < c; i++) {
                int x, y;
                cin >> x >> y;
                ps.push_back(point(x,y));
        }
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        cout << fixed << setprecision(3);
        input();
        cout << solve() << endl;
        return 0;
}

