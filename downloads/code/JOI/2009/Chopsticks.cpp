#include <bits/stdc++.h>
using namespace std;

inline void chmin(int &a, int b){a=min(a,b);}
int n, dp[512][512];
string s;

int solve()
{
        for (int len = 1; len <= n; len++) {
                for (int l = 0; l+len <= n; l++) {
                        int r = l+len;
                        dp[l][r] = r-l;
                        for (int m = l+1; m < r; m++)
                                chmin(dp[l][r], dp[l][m]+dp[m][r]);
                        if(r-l>1 and s[l] == s[r-1]) dp[l][r]--;
                }
        }

        return dp[0][n];
}

void input()
{
        cin >> n >> s;
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
