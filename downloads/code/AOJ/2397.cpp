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

typedef long long ll;
typedef vector<vector<int> > matrix;

using namespace std;
int w, h, n;

void mulmat(matrix a, matrix b){
    
}

int main(){
    while(cin >> w >> h >> n, w || h || n){
        vector<pair<int, int> > ob;
        rep(i,n){
            int x, y;
            cin >> x >> y;
            ob.pb(mp(y,x));
        }
    }
}