#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <bitset>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

int n, hx, hy, dx, dy;
vector<P> c;

double dis(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool dfs(int x, int y, int ne, double day, int S){

    int nx = c[ne].first;
    int ny = c[ne].second;
    double d = dis(x, y, nx, ny);

    rep(i,n) if(!((1<<i)&S) && (dis(x,y,c[i].first,c[i].second)>=dis(dx,dy,c[i].first,c[i].second)-day))
        return false;
    S |= 1 << ne;

//    if(d >= dis(dx,dy,nx,ny) - day) return false;
    if(S == (1<<n)-1) return true;
    bool ok = false;
    rep(i,n) if(!((1<<i) & S)){
        if(ok = dfs(nx,ny,i,d+day,S|(1<<i))) break;
    }
    return ok;
}

int main(){

    while(cin>>n>>hx>>hy>>dx>>dy,n||hx||hy||dx||dy){
        c.clear();
        rep(i,n){
            int a, b;
            cin >> a >> b;
            c.pb(P(a,b));
        }
        bool ok = false;
        rep(i,n){
            if(ok = dfs(hx,hy,i,0,0)) break;
        }
        cout << ((ok)? "YES":"NO") << endl;
    }
}
