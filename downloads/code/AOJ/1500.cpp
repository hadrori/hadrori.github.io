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

int n, m, k, a[16], p[16];
string id;

int dfs(int d, int sum){
    if(d == k){
	if(sum % 10 == 0) return 1;
	else return 0;
    }
    int ret = 0;
    rep(i,m){
	int t = p[d] * a[i];
	ret += dfs(d + 1, sum + t / 10 + t % 10);
    }
    return ret;
}

int main(){
    cin >> n >> id >> m;
    rep(i,m) cin >> a[i];
    int sum = 0;
    k = 0;
    rep(i,id.size()){
	if(id[i] == '*') p[k++] = 2 - (n - i) % 2;
	else{
	    int t = (2 - (n - i) % 2) * (id[i] - '0');
	    sum += t / 10 + t % 10;
	}
    }
    cout << dfs(0, sum % 10) << endl;
    return 0;
}
