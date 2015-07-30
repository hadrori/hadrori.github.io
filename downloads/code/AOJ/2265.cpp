#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

vector<ll> a;
int n;

int main(){
    cin >> n;
    rep(_,n){
	ll t;
	cin >> t;
	a.pb(t);
    }
    sort(rall(a));
    ll ans = 0, cnt = 0;
    rep(i,n-2)if(a[i] < a[i+1] + a[i+2]){
	ans += a[i] + a[i+1] + a[i+2];
	i += 2;
	if(++cnt == 2) break;
    }
    if(cnt != 2) ans = 0;
//    cerr << ans << endl;
    rep(i,n-5)repi(j,i+1,i+6)repi(k,j+1,i+6){
	if(a[i] < a[j] + a[k]){
	    cnt = 0;
	    ll tmp = 0;
	    repi(x,i+1,i+6)if(x != j && x != k){
		if(cnt) tmp += a[x];
		else tmp -= a[x];
		cnt++;
	    }
	    if(tmp > 0){
		tmp = 0;
		repi(x,i,i+6) tmp += a[x];
		ans = max(ans, tmp);
	    }
	}
    }
    cout << ans << endl;
    return 0;
}
