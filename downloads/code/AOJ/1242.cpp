#include <bits/stdc++.h>
using namespace std;
int n, x[128], y[128];

double cpx(int p, int q, int i)
{
        if(y[p] < y[q]) swap(p,q);
        double a = y[p]-i, b = i-y[q];
        return (b*x[p]+a*x[q])/(a+b);
}

int solve()
{
        int ans = 0, li = *min_element(y,y+n), ri = *max_element(y,y+n);
        for (int i = li; i < ri; i++) {
                vector<pair<double,double>> xs;
                for (int j = 0; j < n; j++) {
                        int nj = (j+1)%n;
                        if(y[j] == y[nj] or i < min(y[j], y[nj]) or i+1 > max(y[j], y[nj])) continue;
                        double x1 = cpx(j,nj,i), x2 = cpx(j,nj,i+1);
                        if(x1 > x2) swap(x1, x2);
                        xs.push_back(make_pair(x1,x2));
                }
                sort(begin(xs),end(xs));
                int xr = -2048;
                for (int j = 0; j < (int)xs.size()-1; j+=2) {
                        int l = max(int(floor(xs[j].first)), xr), r = ceil(xs[j+1].second);
                        ans += r-l;
                        xr = r;
                }
        }
        return ans;
}

bool input()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d %d", x+i, y+i);
        return n;
}

int main()
{
        while(input()) printf("%d\n", solve());
        return 0;
}
