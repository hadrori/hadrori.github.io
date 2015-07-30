#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)

string s;
int memo[16];

int main(){
    cin >> s;
    int cur = 0, prev = 0;
    cout << '>';
    rep(i,s.size()){
        prev = cur;
        cur = 0;
        rep(j,16)if(abs(memo[cur]-s[i]) > abs(memo[j]-s[i]))
            cur = j;
        rep(j,abs(cur-prev)) cout << (cur-prev<0? "<<": ">>");
        int d = s[i] - memo[cur];
        int sr = sqrt(abs(d));
        memo[cur] = (int)s[i];
        if(abs(d) < 8) rep(j,abs(d)) cout << (d<0? '-': '+');
        else {
            cout << '<';
            rep(j,abs(d)/sr) cout << '+';
            cout << "[>";
            rep(j,sr) cout << (d<0? '-': '+');
            cout << "<-]>";
            rep(j,abs(d)-abs(d)/sr*sr) cout << (d<0? '-': '+');
        }
        cout << '.';
    }

    return 0;
}
