#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
typedef long long ll;
typedef vector<int> vi;

int main(){
    int n;
    cin >> n;
    vector<vi> c(n,vi(n));
    rep(i,n) rep(j,n) cin >> c[i][j];
    ll ans = 0;
    rep(i,n) rep(j,i) ans += min(c[i][j], c[j][i]);
    cout << ans << endl;
}


