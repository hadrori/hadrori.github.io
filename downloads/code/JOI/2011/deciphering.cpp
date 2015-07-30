#include <bits/stdc++.h>
using namespace std;
const int mod = 10000000;
inline void add(int &a, int b){ a=(a+b)%mod;}

int n, m, fb[32][32], seq[1<<19], dp[2][32];

int solve()
{
        dp[0][26] = 1;
        for (int i = 0; i < n; i++) {
                dp[1][seq[i]] = 0;
                for (int j = 0; j < 27; j++) {
                        if(seq[i] != j) dp[1][j] = dp[0][j];
                        if(!fb[j][seq[i]]) add(dp[1][seq[i]], dp[0][j]);
                }
                swap(dp[0], dp[1]);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) add(ans, dp[0][i]);
        return ans;
}

void input()
{
        cin >> n;
        char c, d;
        for (int i = 0; i < n; i++) {
                cin >> c;
                seq[i] = c-'A';
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
                cin >> c >> d;
                fb[c-'A'][d-'A'] = 1;
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
