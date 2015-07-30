#include <bits/stdc++.h>
using namespace std;
const int mod = 1234567;
long long n, p, h[500010], sum[500010];

int solve()
{
        sum[1] = 1;
        int l = 0, r = 0;
        long long hs = 0;
        for (int i = 0; i < n; i++) {
                while(r <= i) hs += h[r++];
                while(l < r and p < hs) hs -= h[l++];
                sum[r+1] = (sum[r]+(sum[r]-sum[l])%mod+mod)%mod;
        }
        return ((sum[n+1]-sum[n])%mod+mod)%mod;
}

void input()
{
        cin >> n >> p;
        for (int i = 0; i < n; i++) cin >> h[i];
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
