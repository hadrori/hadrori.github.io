#include <iostream>
#include <vector>
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define pb push_back
using namespace std;
typedef long long ll;

int n, k;
vector<ll> a, b;

bool can(double val){
    vector<double> v;
    rep(i,n) v.pb(100.0 * a[i] - val * b[i]);
    sort(rall(v));
    double sum = 0;
    rep(i,n-k) sum += v[i];
    return sum >= 0;
}

int main(){
    while(cin >> n >> k, n || k){
	a.resize(n); b.resize(n);
	rep(i,n) scanf("%lld", &a[i]);
	rep(i,n) scanf("%lld", &b[i]);
	double lb = 0, ub = 128;
	rep(_,100){
	    double mid = (lb + ub) / 2;
	    if(can(mid)) lb = mid;
	    else ub = mid;
	}
	int ans = (int)(lb + 0.5);
	cout << ans << endl;
    }
    return 0;
}
