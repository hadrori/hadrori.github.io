#include <bits/stdc++.h>
using namespace std;

struct point
{
        long long x, y;
        int k;
        point(long long x, long long y, int k) : x(x), y(y), k(k) {}
        bool operator<(const point &p) const { return x!=p.x? x<p.x: y<p.y;}
};
inline bool cmpy(const point &a, const point &b) { return a.y!=b.y? a.y<b.y: a.x!=b.x? a.x<b.x: a.k>b.k;}

const long long inf = 1LL<<50;
int n[2];
long long a[2][32], sum[2][32];

long long solve()
{
        vector<point> vs;
        for (int k = 0; k < 2; k++) {
        for (int s = 0; s < 1<<n[k]; s++) {
                int m = n[k]-__builtin_popcount(s);
                for (int t = 0; t < 1<<m; t++) {
                        long long x = 0, y = 0, z = 0, j = 0;
                        for (int i = 0; i < n[k]; i++) {
                                if(s>>i&1) x += a[k][i];
                                else {
                                        if(t>>j&1) y += a[k][i];
                                        else z += a[k][i];
                                        j++;
                                }
                        }
                        vs.push_back(point((1-k*2)*(x-y),(1-k*2)*(y-z),k));
                }
        }
        }
        sort(vs.begin(),vs.end(),cmpy);
        long long ans = inf;
        vector<point> S; // (x, x+y)
        for (vector<point>::iterator p = vs.begin(); p != vs.end(); p++) {
                if(p->k == 0) {
                        vector<point>::iterator q = upper_bound(S.begin(), S.end(), point(p->x,inf,0));
                        if(q == S.begin()) continue;
                        q--;
                        ans = min(ans, p->x+p->y-q->y);
                }
                else {
                        vector<point>::iterator l = lower_bound(S.begin(), S.end(), point(p->x,-inf,0)),
                                                r = upper_bound(l, S.end(), point(inf,p->x+p->y,0), cmpy);
                        S.erase(l, r);
                        S.insert(l, point(p->x, p->x+p->y, 0));
                }
        }
        return ans;
}

void input()
{
        scanf("%d", n);
        n[1] = n[0]/2;
        n[0] -= n[1];
        for (int i = 0; i < n[0]; i++) scanf("%lld", a[0]+i);
        for (int i = 0; i < n[1]; i++) scanf("%lld", a[1]+i);
}

int main()
{
        input();
        printf("%lld\n", solve());
        return 0;
}
