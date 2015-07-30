#include <bits/stdc++.h>
using namespace std;
int n, m, w, a[100010];
long long p[100010];

bool ok(long long k)
{
        long long res = m, add = 0;
        memset(p,0,sizeof(p));
        for (int i = 0; i < n; i++) {
                if(i >= w) add -= p[i-w];
                if(add + a[i] < k) {
                        p[i] = k - (add+a[i]);
                        add += p[i];
                        res -= p[i];
                        if(res < 0) return 0;
                }
        }
        return 1;
}       

long long solve()
{
        long long sum = 0;
        for (int i = 0; i < n; i++)
                sum += a[i];
        long long lb = 0, ub = (sum+1LL*w*m)/n+100, mid;
        while(ub - lb > 1) {
                mid = (lb+ub)/2;
                if(ok(mid)) lb = mid;
                else ub = mid;
        }
        return lb;
}

void input()
{
        scanf("%d%d%d", &n, &m, &w);
        for (int i = 0; i < n; i++) {
                scanf("%d", a+i);
        }

}

int main()
{
        input();
        cout << solve() << endl;
        return 0;
}
