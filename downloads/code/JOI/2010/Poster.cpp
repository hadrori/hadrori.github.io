#include <bits/stdc++.h>
using namespace std;

int n, k;
string ans;

void rec(int l, int r)
{
        if(r-l==1) {
                ans.push_back('J');
                return;
        }
        int m = (l+r)/2;
        if(k >= m) {
                for (int i = l; i < m; i++) ans.push_back('I');
                rec(m,r);
        }
        else {
                for (int i = l; i < m; i++) ans.push_back('J');
                for (int i = m; i < r; i++) ans.push_back('O');
                return;
        }
}

string solve()
{
        ans = "";
        rec(0,1<<n);
        return ans;
}

void input()
{
        cin >> n >> k;
        k--;
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
