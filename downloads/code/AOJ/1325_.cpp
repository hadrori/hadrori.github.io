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

const int MAX = 20000;

bool p[MAX];

void pcalc(){
    p[0] = p[1] = 1;
    for(int i = 2; i * i < MAX; i++)
	if(!p[i])for(int j = 2 * i; j < MAX; j+= i) p[j] = 1;
    return;
}

int main(){
    pcalc();
    int _;
    cin >> _;
    while(_--){
	complex<int> m;
	cin >> m.real() >> m.imag();
	if(m.real() < 0) m.real() *= -1;
	if(m.imag() < 0) m.imag() *= -1; 
	bool prime = false;
	int n = norm(m);
	if(n == 2) prime = true;
	else if(n % 4 == 1 && !p[n]) prime = true;
	else if((m.real() == 0 && m.imag() % 4 == 3 && !p[m.imag()]) ||
		(m.imag() == 0 && m.real() % 4 == 3 && !p[m.real()])) prime = true;
	cout << (prime? "P": "C") << endl;
    }
    return 0;
}
