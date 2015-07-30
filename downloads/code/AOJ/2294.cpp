#include <bits/stdc++.h>
using namespace std;

int h, n, p, m, K;
int bar[512], res[512];
double dp[2][128][128];

double solve()
{
        res[0] = h-m;
        for (int i = 0; i < h; i++) res[i+1] = res[i]-!bar[i];
        const double qr = 1./(n-1);

        dp[0][0][p] = 1;
        for (int i = 0; i < h; i++) {
                if(bar[i]) {
                        for (int k = 0; k < K+1; k++) swap(dp[0][k][bar[i]-1], dp[0][k][bar[i]]);
                        continue;
                }
                memset(dp[1],0,sizeof(dp[1]));
                for (int k = 0; k < K+1; k++) {
                        const double pr = 1.*(K-k)/res[i];
                        for (int j = 0; j < n; j++) {
                                double r = 1., x = dp[0][k][j];
                                if(j) dp[1][k+1][j-1] += x*pr*qr, r -= qr;
                                if(j < n-1) dp[1][k+1][j+1] += x*pr*qr, r -= qr;
                                dp[1][k+1][j] += x*pr*r;
                                dp[1][k][j] += x*(1-pr);
                        }
                }
                swap(dp[0], dp[1]);
        }
        return *max_element(dp[0][K], dp[0][K]+n);
}

void input()
{
        cin >> h >> n >> p >> m >> K; p--;
        for (int i = 0; i < m; i++) {
                int a, b; cin >> a >> b;
                bar[h-a] = b;
        }
}

int main()
{
        input();
        cout << fixed << setprecision(12) << solve() << endl;
        return 0;
}
