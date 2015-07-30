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

/* 3Dの点 */
struct P3{
    double x, y, z;
    P3() : x(0), y(0), z(0){}
    P3(double x, double y, double z) : x(x), y(y), z(z) {}
    P3 operator-(const P3 &p) const{
	return P3(x-p.x, y-p.y, z-p.z);
    }
};
/* 3Dのノルム */
double norm(const P3 &p){
    return p.x*p.x + p.y*p.y + p.z*p.z;
}

double nt1, nt2, et1, et2;
const double R = 6378.1;

void solve(){
    P3 p1 = P3(cos(nt1)*cos(et1), cos(nt1)*sin(et1), sin(nt1));
    P3 p2 = P3(cos(nt2)*cos(et2), cos(nt2)*sin(et2), sin(nt2));
    double d = norm(p1-p2);
    double th = acos((2 - d) / 2);
    cout << (int)(R*th+0.5) << endl;
    return;
}

int main(){
    while(cin >> nt1 >> et1 >> nt2 >> et2){
	if(nt1==-1 && nt2==-1 && et1==-1 && et2==-1) break;
	nt1 = nt1 / 360 * 2 * PI;
	et1 = et1 / 360 * 2 * PI;
	nt2 = nt2 / 360 * 2 * PI;
	et2 = et2 / 360 * 2 * PI;
	solve();
    }
    return 0;
}
