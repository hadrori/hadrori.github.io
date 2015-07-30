#include <bits/stdc++.h>
using namespace std;

int n, zip[1<<19], s[2048], t[2048], dp[4096][4096], to[4096];
vector<int> vs;
inline void chmax(int &a, int b){ a=max(a,b);}

int solve()
{
        sort(begin(vs),end(vs));
        for (int i = 0; i < 2*n; i++) zip[vs[i]] = i;
        for (int i = 0; i < n; i++) {
                to[zip[s[i]]] = zip[t[i]];
                to[zip[t[i]]] = zip[s[i]];
        }

        n *= 2;
        for (int d = 1; d < n; d++) {
                for (int l = 0; l+d < n; l++) {
                        int r = l+d, p = to[l], q = to[r];
                        chmax(dp[l][r], dp[l][r-1]);
                        if(l < p and p <= r) chmax(dp[l][r], dp[l][p-1]+dp[p+1][r]+1);
                        if(l < q and q <= r) chmax(dp[l][r], dp[l][q-1]+dp[q+1][r]+1);
                }
        }
        return dp[0][n-1];
}

void input()
{
        cin >> n;
        for (int i = 0; i < n; i++) {
                cin >> s[i] >> t[i];
                if(s[i] > t[i]) swap(s[i], t[i]);
                vs.push_back(s[i]);
                vs.push_back(t[i]);
        }
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
