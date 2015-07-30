#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)

string op[128];
int st[256], n;

int solve(){
    memset(st,0,sizeof(st));
    int ans = 0, s = 1;
    rep(i,n) {
        st[op[i][0]] ^= 1;
        if(s == st['l'] and s == st['r']) ++ans, s ^= 1;
    }
    return ans;
}

bool input(){
    cin >> n;
    if(!n) return 0;
    rep(i,n) cin >> op[i];
    return 1;
}

int main(){
    while(input()) cout << solve() << endl;
    return 0;
}
