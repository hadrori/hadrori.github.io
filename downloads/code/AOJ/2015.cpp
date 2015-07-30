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

int combi(int n){
    return n*(n-1)/2;
}

int main(){
    int n, m;
    while(cin>>n>>m,n||m){        
        vec x, y;
        x.pb(0);
        y.pb(0);
        rep(i,n){
            int h;
            cin >> h;
            h += y[i];
            y.pb(h);
        }
        rep(i,m){
            int w;
            cin >> w;
            w += x[i];
            x.pb(w);
        }
        map<int,int> cnt;
        rep(i,n+1)rep(j,m+1){
            cnt[y[i]-x[j]]++;
        }
        int ans = 0;
        repi(i,-x[m],y[n]+1){
            ans += combi(cnt[i]);
        }
        cout << ans << endl;
    }
}
