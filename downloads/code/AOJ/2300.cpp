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
#define all(c) (c).begin(),(c).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

struct C{
    double l, a, b;
};

int n, m;
double ans;
vector<C> c;

double dist(C c1, C c2){
    return (c1.l-c2.l)*(c1.l-c2.l) + (c1.a-c2.a)*(c1.a-c2.a) + (c1.b-c2.b)*(c1.b-c2.b);
}

void dfs(int d, vec v){

    if(d==m){
        double sum = 0;
        rep(i,v.size())repi(j,i+1,v.size()){
            sum += dist(c[v[i]],c[v[j]]);
        }
        ans = max(ans, sum);
    }else {
        repi(i,v[d-1]+1,n){
            v.pb(i);
            dfs(d+1,v);
            v.pop_back();
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    rep(i,n){
        C t;
        cin >> t.l >> t.a >> t.b;
        c.pb(t);
    }
    vec v;
    rep(i,n){
        v.pb(i);
        dfs(1,v);
        v.pop_back();
    }
    printf("%.20f\n",ans);
}

