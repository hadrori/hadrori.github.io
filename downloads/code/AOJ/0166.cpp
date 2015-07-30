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

double g1, g2, sum1, sum2;
int m, n;

void solve(){
    g1 = 0; g2 = 0;
    sum1 = 0; sum2 = 0; m--;
    int v;
    
    rep(i,m){
	cin >> v;
	sum1 += v;
	g1 += sin(1.0*v/360*2*PI);
    }
    v = 360 - sum1;
    g1 += sin(1.0*v/360*2*PI);
    cin >> n; n--;
    rep(i,n){
	cin >> v;
	sum2 += v;
	g2 += sin(1.0*v/360*2*PI);
    }
    v = 360 - sum2;
    g2 += sin(1.0*v/360*2*PI);
    cout << (abs(g1-g2)<EPS? 0: g1+EPS>g2? 1: 2) << endl;
    return;
}

int main(){
    while(cin >> m, m){
	solve();
    }
    return 0;
}
