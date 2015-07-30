#include <bits/stdc++.h>

namespace D2
{
const double eps = 1e-8;

struct point
{
        double x, y;
        point():x(0),y(0){}
        point(double x, double y):x(x),y(y){}

        point operator+=(const point &p){ x+=p.x; y+=p.y; return *this;}
        point operator-=(const point &p){ x-=p.x; y-=p.y; return *this;}
        point operator*=(const double &d){ x*=d; y*=d; return *this;}
        point operator/=(const double &d){ x/=d; y/=d; return *this;}
        point operator+(const point &p)const{ return point(*this)+=p;}
        point operator-(const point &p)const{ return point(*this)-=p;}
        point operator*(const double &d)const{ return point(*this)*=d;}
        point operator/(const double &d)const{ return point(*this)/=d;}
        point operator-()const{ return point(-x,-y);}
        bool operator<(const point &p) const { return std::abs(x- p.x)>eps ? x < p.x-eps : y < p.y-eps;}
        bool operator==(const point &p) const { return std::abs(x-p.x)<eps and std::abs(y-p.y)<eps;}
        bool operator!=(const point &p) const { return !(point(*this)==p);}

        double norm() const { return x*x+y*y;}
        double abs() const { return sqrt(norm());}
        double det(const point &p) const { return x*p.y-y*p.x;}
};

struct line
{
        point a, b;
        line(){}
        line(point a, point b):a(a),b(b){}

        point vec() const { return b-a;}
};

inline bool ill(const line &l, const line &m){ return abs(l.vec().det(m.vec())) > eps;}
inline point cll(const line &l, const line &m){ return l.a+l.vec()*(m.vec().det(m.a-l.a)/m.vec().det(l.vec()));}

}

using namespace std;
using namespace D2;

int n, m, f[1024];
vector<point> V, W;
vector<line> E, F;

bool same(const line &l, const line &m){
        return abs(l.vec().det(m.vec())) < eps and abs(l.vec().det(m.a-l.a)) < eps;
}

int solve()
{
        
        for (int i = 0; i < n; i++) {
                if(!f[i]) E.push_back(F[i]);
                for (int j = i+1; j < n; j++)
                        if(!f[j] and same(F[i], F[j])) f[j] = 1;
        }

        m = E.size();
        int e = m;
        for(auto &a: E) {
                W.clear();
                for(auto &b: E) {
                        if(!ill(a,b)) continue;
                        point p = cll(a,b);
                        V.push_back(p);
                        W.push_back(p);
                }
                sort(begin(W),end(W));
                e += unique(begin(W),end(W))-begin(W);
        }
        sort(begin(V),end(V));        
        int v = unique(begin(V),end(V))-begin(V);
        return 1-v+e;
}

void input()
{
        cin >> n;
        int a, b, c, d;
        for (int i = 0; i < n; i++) {
                cin >> a >> b >> c >> d;
                F.push_back(line(point(a,b),point(c,d)));
        }

}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
