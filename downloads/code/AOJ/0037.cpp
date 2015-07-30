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

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
string dir = "LURD";
bool path[16][16][4];

bool inrange(int x, int y){
    return x >= 0 && x < 5 && y >= 0 && y < 5;
}

int main(){
    rep(i,9)
	if(i%2)rep(j,5){
		char c;
		cin >> c;
		if(c == '1'){
		    path[i/2][j][3] = true;
		    path[i/2+1][j][1] = true;
		}
	}
	else rep(j,4){
		char c;
		cin >> c;
		if(c == '1'){
		    path[i/2][j][2] = true;
		    path[i/2][j+1][0] = true;
		}
	}
    int x = 0, y = 0, d = 2;
    int cnt = 0;
    do{
	rep(i,4){
	    int dd = (d + 3 + i) % 4;
	    if(path[y][x][dd]){
		x += dx[dd]; y += dy[dd];
		d = dd;
		cout << dir[dd];
		break;
	    }
	}
    }while(x || y);
    cout << endl;
    return 0;
}
