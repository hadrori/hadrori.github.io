#include <bits/stdc++.h>
using namespace std;
 
int n, m, r, x[100010], y[100010];
vector<int> ys[10010];
 
inline int dist(int a, int b, int c, int d) { return (a-c)*(a-c)+(d-b)*(d-b);}
 
int solve()
{
        for (int i = 0; i < 10010; i++) sort(begin(ys[i]),end(ys[i]));
 
        int ans = 0;
        for (int i = 0; i < n; i++) {
                for(int xx = max(0,x[i]-4*r); xx <= min(10000, x[i]+4*r); xx++) {
                        auto lb = lower_bound(begin(ys[xx]),end(ys[xx]), y[i]-4*r),
                             ub = upper_bound(begin(ys[xx]),end(ys[xx]), y[i]+4*r);
                        for(auto it = lb; it != ub; it++)
                                if(dist(x[i], y[i], xx, *it) <= 16*r*r) ans++;
                }
        }
        return ans;
}
 
bool input()
{
        scanf("%d%d%d", &n, &m, &r);
        for (int i = 0; i < n; i++) scanf("%d%d", x+i, y+i);
        for (int i = 0; i < 10010; i++) ys[i].clear();
        for (int i = 0; i < m; i++) {
                int xx, yy;
                scanf("%d%d", &xx, &yy);
                ys[xx].push_back(yy);
        }
        return n or m;
}
 
int main()
{
        while(input()) printf("%d\n", solve());
        return 0;
}