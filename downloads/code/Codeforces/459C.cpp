#include <bits/stdc++.h>
using namespace std;

int n, k, d, kad[1024][1024];

void solve()
{

        if(d*log(k) < log(n-1)+1e-8) {
                puts("-1");
                return;
        }
        
        for (int i = 0; i < n; i++) {
                int res = i;
                for (int j = 0; j < d; j++) {
                        kad[i][j] = res%k;
                        res /= k;
                }
        }
        for (int j = 0; j < d; j++) {
                for (int i = 0; i < n; i++) {
                        printf("%d ", kad[i][j]+1);
                }
                puts("");
        }
}

void input()
{
        scanf("%d%d%d", &n, &k, &d);
}

int main()
{
        input();
        solve();
        return 0;
}
