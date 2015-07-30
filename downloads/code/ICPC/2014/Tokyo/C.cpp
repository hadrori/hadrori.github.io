#include <bits/stdc++.h>
using namespace std;

int n, m, seq[1024];

int solve()
{
        int ans = n+1;
        for (int i = 0; i <= n; i++)
                if(seq[i]) ans += 2;
        return ans;
}

void input()
{
        cin >> n >> m;
        int c, d;
        for (int i = 0; i < m; i++) {
                cin >> c >> d;
                for (int j = c; j < d; j++) seq[j] = 1;
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
