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

bool visited[25][25][4][16];// 0 1 2 3: u d l r
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
vector<string> table;
int h, w;

int command(int x, int y, int* d, int* m){
    switch(table[y][x]){
    case '<': *d = 2; break;
    case '>': *d = 3; break;
    case '^': *d = 0; break;
    case 'v': *d = 1; break;
    case '_':
	if(*m) *d = 2;
	else *d = 3;
	break;;
    case '|':
	if(*m) *d = 0;
	else *d = 1;
	break;
    case '?': return 2;
    case '.': break;
    case '@': return 1;
    case '+': *m = (*m + 1) % 16; break;
    case '-': *m = (*m + 15) % 16; break;
    }
    if(table[y][x] >= '0' && table[y][x] <= '9')
	*m = table[y][x] - '0';
    return 0;
}

bool rec(int x, int y, int d, int m){
    if(visited[x][y][d][m]) return false;
    visited[x][y][d][m] = true;
//    cerr << "(" << x << "," << y << ")" << " d = " << d << " mem = " << m << endl;
    int state = command(x,y,&d,&m);
    if(state == 1) return true;
    if(state == 2){rep(i,4) if(rec((x+dx[i]+w)%w,(y+dy[i]+h)%h,i,m)) return true;}
    else if(rec((x+dx[d]+w)%w,(y+dy[d]+h)%h,d,m)) return true;
    return false;
}

int main(){
    cin >> h >> w;
    table.resize(h);
    rep(i,h) cin >> table[i];
    cout << (rec(0,0,3,0)? "YES": "NO") << endl;
    return 0;
}
