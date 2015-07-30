#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)

int seq[5];
void input(){ rep(i,5) cin >> seq[i];}

int solve(){
    int sum = 0;
    rep(i,5) sum += max(40LL, seq[i]);
    return sum / 5;
}

signed main(){
    input();
    cout << solve() << endl;
    return 0;
}
