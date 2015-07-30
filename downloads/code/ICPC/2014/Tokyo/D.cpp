#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int n, b;
double d, p[16], h[16];

inline double sq(double x){ return x*x;}

bool intersect(double th, int i, int j, int k)
{
        const double bd = d/(k+1), pos = p[i] - bd*j;
        if(pos < 0 or bd < pos) return 0;
        const double v = sqrt(bd/sin(2*th)), vx = v*cos(th), vy = v*sin(th);
        const double y = -0.5*sq(pos)/sq(vx)+vy/vx*pos;
        return y < h[i];
}

bool attempt(double th, int k)
{
        for (int i = 0; i < n; i++)
                for (int j = 0; j <= k; j++)
                        if(intersect(th,i,j,k)) return 0;
        return 1;
}

double search(int k)
{
        double lb = pi/4, ub = pi, mid;
        for (int i = 0; i < 100; i++) {
                mid = (lb+ub)/2;
                if(attempt(mid,k)) ub = mid;
                else lb = mid;
        }
        return ub;
}

double solve()
{
        double ans = 1e9;
        for (int i = 0; i <= b; i++) {
                double bd = d/(i+1);
                if(attempt(pi/4.,i)) ans = min(ans, sqrt(bd));
                else ans = min(ans, sqrt(bd/sin(2*search(i))));
        }
        return ans;
}

void input()
{
        cin >> d >> n >> b;
        for (int i = 0; i < n; i++)
                cin >> p[i] >> h[i];
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        cout << fixed << setprecision(12);
        input();
        cout << solve() << endl;
        return 0;
}
