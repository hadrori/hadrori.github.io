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
#define rall(c) (c).rbegin(),(c).rend()

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

int n, m, k;
double ans;

void dfs(vec v){
    if(v.size() == n){
        int sum = 0;
        rep(i,v.size()) sum += v[i];
        ans += 1.0*max(1,sum-k)/pow(1.0*m,n);
        return;
    }
    repi(i,1,m+1){
        v.pb(i);
        dfs(v);
        v.pop_back();
    }
    return;
}

int main(){

    while(cin>>n>>m>>k,n||m||k){
        ans = 0;
        vec v;
        dfs(v);
        printf("%.8f\n",ans);
    }
}
