#include <iostream>
#include <string>
#define rep(i,a) for(int i = 0;i < (a); i++)
using namespace std;
typedef long long ll;

ll power(long long x, long long k) {
    if (k == 0)     return 1;
    if(x > 1000000000) return -1;
    if (k % 2 == 1){
        ll t = power(x, k-1);
        if(t < 0) return t;
        else return t * x;
    }
    else return power(x*x, k/2);
}

int main(){
    int n, T;
    string f;
    cin >> n >> T >> f;
    ll sum = 0;
    rep(i,f.size())if(f[i] == 'n'){
        ll p = power(n, f[i+2] - '0');
        if(p < 0 || p * T > 1000000000 || sum + p * T > 1000000000){
            cout << "TLE\n";
            return 0;
        }
        sum += p * T;
    }
    if(sum > 1000000000) cout << "TLE\n";
    else cout << sum << endl;
    return 0;
}
