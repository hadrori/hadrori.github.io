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

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<P> > d(n+1);
    mat d(n);
    rep(i,m){
        int a, b, w;
        cin >> a >> b >> w;
        d[a].pb(P(b,w));
    } 
    
    repi(i,1,n){
        rep()
    }
}
