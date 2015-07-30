#include <bits/stdc++.h>

namespace D2
{
struct point
{
        int x, y;
        point():x(0),y(0){}
        point(int x, int y):x(x),y(y){}

        point operator-=(const point &p){ x-=p.x; y-=p.y; return *this;}
        point operator-(const point &p)const{ return point(*this)-=p;}
        bool operator<(const point &p) const { return x!=p.x ? x < p.x : y < p.y;}

        int norm() const { return x*x+y*y;}
        int dot(const point &p) const { return x*p.x+y*p.y;}
        int cross(const point &p) const { return x*p.y-y*p.x;}
};

std::ostream &operator<<(std::ostream &os, const point &p) { os << "(" << p.x << "," << p.y << ")"; return os; }

int ccw(point a, point b, point c)
{
        b -= a, c -= a;
        if (b.cross(c) > 0)        return +1;
        if (b.cross(c) < 0)        return -1;
        if (b.dot(c) < 0)          return +2;
        if (b.norm() < c.norm())   return -2;
        return 0;
}
}

using namespace std;
using namespace D2;

int n, dp[128][128];
vector<point> ps;
point c;
inline void chmax(int &a, int b){a=max(a,b);}

bool cmp(const point &p, const point &q)
{
        point a = c-p, b = c-q;
        return atan2(a.x,a.y)<atan2(b.x,b.y);
}

int solve()
{
        sort(begin(ps),end(ps));

        int ans = 3;
        for (int i = 0; i < n; i++) {
                c = ps[i];
                sort(begin(ps),begin(ps)+i,cmp);
                memset(dp, 0, sizeof(dp));
                for (int j = i; j >= 0 ; j--)
                        for (int k = j-1; k >= 0; k--) {
                                if(j == i) dp[j][k] = 2;
                                chmax(ans, dp[j][k]);
                                for (int l = k-1; l >= 0; l--)
                                        if(ccw(ps[j],ps[k],ps[l]) == 1)
                                                chmax(dp[k][l], dp[j][k]+1);
                        }
        }
        return ans;
}

void input()
{
        cin >> n;
        for (int i = 0; i < n; i++) {
                int x, y; cin >> x >> y;
                ps.push_back(point(x,y));
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
