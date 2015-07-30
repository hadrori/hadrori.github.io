#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, c, x[512];

double solve()
{
        double ans = 0;
        for (int i = 0; i < n; i++) scanf("%d", x+i+1);
        while(m--){
                scanf("%d%d%d", &u, &v, &c);
                ans = max(ans, 1.*(x[u]+x[v])/c);
        }
        return ans;
}

int main()
{
        scanf("%d%d", &n, &m);
        printf("%.12f\n", solve());
        return 0;
}
