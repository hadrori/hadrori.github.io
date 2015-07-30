#include <bits/stdc++.h>
using namespace std;
#define int long long

int m[8], val[8][80010], num[8][80010], len[8][80010];

void solve()
{
        for (int i = 0; i < 2; i++)
                for (int j = 0; j < m[i]; j++)
                        len[i][j+1] = len[i][j]+num[i][j];
        int head[2] = {};
        while(head[0]<m[0] and head[1]<m[1]) {
                len[2][m[2]+1] = min(len[0][head[0]+1], len[1][head[1]+1]);
                num[2][m[2]] = len[2][m[2]+1]-len[2][m[2]];
                for (int i = 0; i < 2; i++) {
                        val[2][m[2]] += val[i][head[i]];
                        if(len[i][head[i]+1]==len[2][m[2]+1]) head[i]++;
                }
                m[2]++;
        }
        for (int i = 0; i < 2; i++) {
                while(head[i] < m[i]) {
                        len[2][m[2]+1] = len[i][head[i]+1];
                        num[2][m[2]] = len[2][m[2]+1]-len[2][m[2]];
                        val[2][m[2]] = val[i][head[i]];
                        head[i]++;
                        m[2]++;
                }
        }
        // ok before here

        int carry = 0;
        for (int i = 0; i < m[2]; i++) {
                int k = val[2][i]+carry;
                val[3][m[3]] = k%10;
                num[3][m[3]] = 1;
                len[3][m[3]+1] = len[3][m[3]]+1;
                m[3]++;
                if(num[2][i] > 1) {
                        k = val[2][i]+k/10;
                        val[3][m[3]] = k%10;
                        num[3][m[3]] = num[2][i]-1;
                        len[3][m[3]+1] = len[3][m[3]]+num[3][m[3]];
                        m[3]++;
                }
                carry = k/10;
        }
        if(carry) {
                val[3][m[3]] = carry;
                num[3][m[3]] = 1;
                len[3][m[3]+1] = len[3][m[3]]+1;
                m[3]++;
        }
        int pv = val[3][0];
        for (int i = 0; i < m[3]; i++) {
                if(val[3][i] != pv) {
                        val[4][m[4]] = pv;
                        len[4][m[4]+1] = len[3][i];
                        num[4][m[4]] = len[4][m[4]+1]-len[4][m[4]];
                        m[4]++;
                        pv = val[3][i];
                }
        }
        val[4][m[4]] = pv;
        len[4][m[4]+1] = len[3][m[3]];
        num[4][m[4]] = len[4][m[4]+1]-len[4][m[4]];
        m[4]++;
        cout << m[4] << endl;
        for (int i = 0; i < m[4]; i++)
                cout << val[4][m[4]-i-1] << ' ' << num[4][m[4]-i-1] << endl;

}

void input()
{
        for (int i = 0; i < 2; i++) {
                cin >> m[i];
                for (int j = 0; j < m[i]; j++)
                        cin >> val[i][m[i]-j-1] >> num[i][m[i]-j-1];
        }
}

signed main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
