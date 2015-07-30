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

int ans;
int table[12][6];
bool visited[12][6];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

bool inrange(int x, int y){return x >= 0 && x < 6 && y >= 0 && y < 12;}

int countPuyo(int x, int y){
    int ret = 1;
    rep(i,4){
	int nx = x + dx[i];
	int ny = y + dy[i];
	if(inrange(nx,ny) && !visited[ny][nx] && table[y][x] == table[ny][nx]){
	    visited[ny][nx] = true;
	    ret += countPuyo(nx, ny);
	}
    }
    return ret;
}

void vanish(int x, int y){
    int c = table[y][x];
    table[y][x] = 0;
    rep(i,4){
	int nx = x + dx[i];
	int ny = y + dy[i];
	if(inrange(nx,ny) && table[ny][nx] == c) vanish(nx,ny);
	if(inrange(nx,ny) && table[ny][nx] == -1) table[ny][nx] = 0;
    }
}

void fall(){
    rep(x,6){
	bool falling = false;
	int bottom = 0;
	repd(y,11,0){
	    if(!falling && !table[y][x]){
		falling = true;
		bottom = y;
	    }
	    if(falling && table[y][x]){
		int dis = bottom - y;
		repd(i,bottom,0){
		    if(i >= dis) table[i][x] = table[i-dis][x];
		    else table[i][x] = 0;
		}
		falling = false;
		y = bottom;
	    }
	}
    }
}

int main(){
    int n;
    cin >> n;
    while(n--){
	ans = 0;
	rep(i,12)rep(j,6){
	    char c;
	    cin >> c;
	    if(c == '.') table[i][j] = 0;
	    else if(c == 'O') table[i][j] = -1;
	    else table[i][j] = c;
	}
	bool did = true;
	while(did){
	    did = false;
	    memset(visited,0,sizeof(visited));
	    rep(i,12)rep(j,6)
		if(table[i][j] > 0 && !visited[i][j]){
		    visited[i][j] = true;
		    if(countPuyo(j,i) >= 4){
			did = true;
			vanish(j,i);
		    }
		}
		else visited[i][j] = true;
	    if(did){
		ans++;
		fall();
		/*
		if(ans < 6){
		    rep(i,12){
			rep(j,6) printf("%2d ", table[i][j]);
			cerr << endl;
		    }
		    cerr << endl;
		}
		*/
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
