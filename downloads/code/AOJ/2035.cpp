#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)
 
string s;
int dp[2048][2048], to[2048][2048];
 
int rec(int l, int r) {
    int &ret = dp[l][r];
    if(~ret) return ret;
    if(l == r) return ret = 1;
    if(l > r) return ret = 0;
    if(s[l] == s[r]) {
        to[l][r] = 3;
        return ret = rec(l+1,r-1)+2;
    }
    int a = rec(l+1,r), b = rec(l,r-1);
    if(a > b) {
        to[l][r] = 1;
        return ret = a;
    }
    to[l][r] = 2;
    return ret = b;
}
 
string solve() {
    memset(dp,-1,sizeof(dp));
    int l = 0, r = s.size()-1, nl, nr;
    rec(l,r);
    string x = "", y = "";
    while(l < r) {
        nl = l; nr = r;
        if(to[l][r] == 3) x.push_back(s[l]);
        if(to[l][r]&1) nl++;
        if(to[l][r]&2) nr--;
        l = nl; r = nr;
    }
    y = x;
    if(l == r) x.push_back(s[l]);
    reverse(begin(y),end(y));
    return x+y;
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    for(int t = 0; cin >> s; t++) {
        cout << solve() << endl;
    }
    return 0;
}