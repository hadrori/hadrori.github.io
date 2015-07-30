#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ll M, cd, cr;
    int rd, rr;
    cin >> M >> rd >> rr >> cd >> cr;
    ll s = cd * 100 / rd;
    if(cd * 100 % rd) s++;
    ll t = cr * 100 / rr;
    if(cr * 100 % rr) t++;
    if(M - s - t < 0) cout << -1 << endl;
    else cout << M - s - t << endl;
    return 0;
}
