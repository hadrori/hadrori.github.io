#include <bits/stdc++.h>
using namespace std;
const string s = "IMLU";
string t;
int x, n, seq[32];

int left()
{
        int res = seq[0];
        for (int i = 1; i < n; i+=2) {
                if(seq[i] == -1) res += seq[i+1];
                else res *= seq[i+1];
        }
        return x==res;
}

int mul()
{
        for (int i = 1; i < n; i+=2) {
                if(t[i] == '*') {
                        seq[i+1] *= seq[i-1];
                        seq[i] = -1;
                        seq[i-1] = 0;
                }
        }
        return left();
}

char solve()
{
        n = t.size();
        for (int i = 0; i < n; i++) {
                if(t[i] == '+') seq[i] = -1;
                else if(t[i] == '*') seq[i] = -2;
                else seq[i] = t[i]-'0';
        }
        return s[(left()<<1)|mul()];
}

void input()
{
        cin >> t >> x;
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
