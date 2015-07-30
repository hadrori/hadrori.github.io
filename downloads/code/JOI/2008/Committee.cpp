#include <bits/stdc++.h>
using namespace std;

int n, y[100010], p[100010], ans;

int solve()
{
        ans = -100;
        for (int i = n; i > 0; i--){
                ans = max(ans, y[i]);
                if(y[i] > 0) y[p[i]] += y[i];
        }

        return ans;
}

void input()
{
        cin >> n;
        for (int i = 0; i < n; i++)
                cin >> p[i+1] >> y[i+1];
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
