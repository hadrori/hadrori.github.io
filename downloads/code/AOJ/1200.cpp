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

const int MAX = (1<<15)+1;

bool p[MAX];
vi prime;
int n;

void pcalc(){
    rep(i,MAX)p[i] = (i<2)? false: true;
    rep(i,MAX)if(p[i]){
	prime.pb(i);
	for(int j = 2*i; j < MAX; j += i) p[j] = false;
    }
    return;
}

void solve(){
    int ans = 0;
    for(int i = 0; prime[i] <= n/2; i++){
	if(p[n-prime[i]]) ans++;
    }
    cout << ans << endl;
    return;
}

int main(){
    pcalc();
    
    while(cin >> n, n){
	solve();
    }
    return 0;
}
