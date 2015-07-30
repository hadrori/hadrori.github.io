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

using namespace std;

int main(){
    int w, n;
    cin >> w >> n;
    vector<int> am;
    rep(i,w+1) am.pb(i);
    rep(i,n){
        int a, b;
        scanf("%d,%d",&a,&b);;
        swap(am[a],am[b]);
    }
    repi(i,1,w+1) cout << am[i] << endl;
}
