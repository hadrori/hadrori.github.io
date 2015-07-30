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

int n, k;
vi c;

void init(){
    c.clear();
    c.resize(n);
    return;
}
void input(){
    rep(i,n) cin >> c[i];
    return;
}
void solve(){
    int tea = 1;
    rep(i,n-k+1){
	int tmp = 1;
	repi(j,i,k+i) tmp *= c[j];
	tea = max(tea, tmp);
    }
    int stu = 1;
    rep(i,n)rep(j,i){
	swap(c[i],c[j]);
	rep(a,n-k+1){
	    int tmp = 1;
	    repi(b,a,k+a) tmp *= c[b];
	    stu = max(stu, tmp);
	}
	swap(c[i],c[j]);
    }
//    cerr << tea << ' ' << stu << endl;
    if(stu - tea < 0) cout << "NO GAME" << endl;
    else cout << stu - tea << endl;
    return;
}

int main(){
    while(cin >> n >> k, n || k){
	init();
	input();
	solve();
    }
    return 0;
}
