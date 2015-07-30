#include <bits/stdc++.h>
using namespace std;

int n, len, cst;
string s;

void solve()
{
        cst = 0; len = n;
        int cnt = 0;
        char pv = 'O';
        s = "IO"+s+"OI";
        for(auto &c: s) {
                if(pv != c) {
                        if(cnt%2) cst += cnt/2;
                        else if(cnt){
                                cst += (cnt-1)/2+1;
                                len--;
                        }
                        pv = c;
                        cnt = 1;
                }
                else cnt++;
        }
}

void output()
{
        cout << cst << endl;
        cout << len << endl;
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
        solve();
        output();
        return 0;
}
