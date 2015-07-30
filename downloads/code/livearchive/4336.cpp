#include <bits/stdc++.h>
using namespace std;

int n, used[64][53];
string dp[64][64], f[64], ans;

void update(int u, int v)
{
        string tmp = dp[u][v];
        string tmp2 = tmp;
        reverse(tmp2.begin(),tmp2.end());
        if(u == v) tmp += tmp2;
        else {
                tmp.push_back(f[u][v]);
                tmp += tmp2;
        }
        if(tmp.size() > ans.size()) ans = tmp;
        else if(tmp.size() == ans.size() and tmp < ans) ans = tmp;
}

string solve()
{
        ans = "";
        used[0][n-1] = 1;
        for (int i = 0; i < n; i++) {
                for (int j = n-1; j >= i; j--) {
                        if(!used[i][j]) continue;
                        update(i,j);
                        for (int ni = i+1; ni < n; ni++) {
                                for (int nj = j-1; nj >= ni; nj--) {
                                        if(f[i][ni] != f[nj][j]) continue;
                                        string tmp = dp[i][j];
                                        tmp.push_back(f[i][ni]);
                                        if(!used[ni][nj] or dp[ni][nj].size() < tmp.size() or
                                           (dp[ni][nj].size() == tmp.size() and tmp < dp[ni][nj])) {
                                                used[ni][nj] = 1;
                                                dp[ni][nj] = tmp;
                                        }
                                }
                        }
                }
        }
        return ans;
}

void init()
{
        memset(used,0,sizeof(used));
        for (int i = 0; i < 64; i++) {
                for (int j = 0; j < 64; j++) {
                        dp[i][j] = "";
                }
        }
}

void input()
{
        init();
        cin >> n;
        for (int i = 0; i < n; i++) cin >> f[i];
}

int main()
{
        int T; cin >> T;
        while(T--) {
                input();
                cout << solve() << endl;
        }
        return 0;
}
