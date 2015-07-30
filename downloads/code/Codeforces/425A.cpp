#include <bits/stdc++.h>
using namespace std;

int n, k, a[256];

int solve()
{
        int ans = a[0];
        for (int l = 0; l < n; l++)
                for (int r = l; r < n; r++) {
                        priority_queue<int> in, out;
                        for (int i = 0; i < n; i++) {
                                if(i < l or r < i) out.push(a[i]);
                                else in.push(-a[i]);
                        }
                        int j = 0, sum = 0;
                        while(!in.empty() and !out.empty() and j < k) {
                                int x = -in.top(), y = out.top();
                                out.pop();
                                if(x < y) {
                                        j++;
                                        sum += y;
                                        in.pop();
                                }
                                else break;
                        }
                        while(!in.empty()) {
                                sum -= in.top();
                                in.pop();
                        }
                        ans = max(ans, sum);
                }

        return ans;
}

void input()
{
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];

}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
