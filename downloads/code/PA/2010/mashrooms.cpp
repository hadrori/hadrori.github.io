#include <bits/stdc++.h>
using namespace std;

int n, t, a[1<<20];

long long solve()
{
        long long ans = (1LL*t/2+1)*a[0], sum = a[0], r;
        for (int i = 1; i < n; i++) {
                if(t < i) break;
                r = t-i;
                ans = max(ans, sum+(r+1)/2*a[i-1]+(r/2+1)*a[i]);
                sum += a[i];
        }
        
        return ans;
}

void input()
{
        scanf("%d%d", &n, &t);
        for (int i = 0; i < n; i++) scanf("%d", a+i);
}

int main()
{
        input();
        printf("%lld\n", solve());
        return 0;
}