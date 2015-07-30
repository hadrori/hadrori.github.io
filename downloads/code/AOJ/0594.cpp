#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)

int w, h, N, x, y, tx, ty;

void input(){cin >> w >> h >> N;}

int solve(){
    int ans = 0;
    cin >> x >> y;
    x--; y--;
    N--;
    while(N--){
        cin >> tx >> ty;
        tx--; ty--;
        if((tx >= x && ty <= y) || (tx <= x && ty >= y)) ans += abs(tx-x) + abs(ty-y);
        else {
            int dx = abs(tx-x), dy = abs(ty-y);
            ans += min(dx, dy) + abs(dx-dy);
        }
        x = tx; y = ty;
    }
    return ans;
}

signed main(){
    input();
    cout << solve() << endl;
    return 0;
}
