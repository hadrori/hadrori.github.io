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
#define EPS 1e-8
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

int main(){
    int l[10], v[2];
    while(~scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
		 l, l+1, l+2, l+3, l+4, l+5, l+6, l+7, l+8, l+9, v, v+1)){
	double t = 1.0 * v[0] / (v[0] + v[1]);
	int sum = 0;
	rep(i,10) sum += l[i];
	double pos = t * sum;
	int cur = 0;
	while(l[cur] < pos) pos -= l[cur++];
	cout << cur + 1 << endl;
    }
    return 0;
}
