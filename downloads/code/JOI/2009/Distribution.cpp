#include <bits/stdc++.h>
using namespace std;

int n, m, s[10010], a[10010];
vector<int> G[10010];

void rec(int v, int sum, int &M, int &p)
{
        sum += a[v];
        if(sum > M) {
                p = v;
                M = sum;
        }
        for(auto &u: G[v]) rec(u,sum,M,p);
}

int solve()
{
        int ans = 0;
        for (int i = 0; i < m; i++) {
                int p = 0, M = 0;
                rec(1,0,M,p);
                ans += M;
                while(p) {
                        a[p] = 0;
                        p = s[p];
                }
        }
        return ans;
}

void input()
{
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
                cin >> s[i] >> a[i];
                G[s[i]].push_back(i);
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
