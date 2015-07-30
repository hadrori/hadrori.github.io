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

bool inrange(int i, int j){
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}
int main(){
    string tmp;
    while(cin >> tmp){
	bool table[8][8];
	rep(i,8) table[0][i] = tmp[i]=='1'? true: false;
	rep(i,7){
	    cin >> tmp;
	    rep(j,8) table[i+1][j] = tmp[j]=='1'? true: false;
	}
	bool ok = false;
	rep(i,8){
	    rep(j,8){
		if(table[i][j]){
		    ok = true;
		    if(inrange(i+1,j+1) && table[i+1][j] &&
		       table[i][j+1] && table[i+1][j+1]) cout << "A\n";
		    else if(inrange(i+3,j) && table[i+1][j] &&
			    table[i+2][j] && table[i+3][j]) cout << "B\n";
		    else if(inrange(i,j+3) && table[i][j+1] &&
			    table[i][j+2] && table[i][j+3]) cout << "C\n";
		    else if(inrange(i+2,j-1) && table[i+1][j-1] &&
			    table[i+1][j] && table[i+2][j-1]) cout << "D\n";
		    else if(inrange(i+1,j+2) && table[i][j+1] &&
			    table[i+1][j+1] && table[i+1][j+2]) cout << "E\n";
		    else if(inrange(i+2,j+1) && table[i+1][j] &&
			    table[i+1][j+1] && table[i+2][j+1]) cout << "F\n";
		    else cout << "G\n";
		    break;
		}
	    }
	    if(ok) break;
	}
    }
    return 0;
}
