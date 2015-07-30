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

typedef complex<double> Complex;
const Complex I(0, 1);

void fft(int n, double theta, Complex a[]) {
    for (int m = n; m >= 2; m >>= 1) {
	int mh = m >> 1;
	for (int i = 0; i < mh; i++) {
	    Complex w = exp(i*theta*I);
	    for (int j = i; j < n; j += m) {
		int k = j + mh;
		Complex x = a[j] - a[k];
		a[j] += a[k];
		a[k] = w * x;
	    }
	}
	theta *= 2;
    }
    int i = 0;
    for (int j = 1; j < n - 1; j++) {
	for (int k = n >> 1; k > (i ^= k); k >>= 1);
	if (j < i) swap(a[i], a[j]);
    }
}

int main(){
    int n;
    cin >> n;
    return 0;
}
