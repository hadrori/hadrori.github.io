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

int main(){
    int w, d;
    while(cin>>w>>d,w||d){
        vec h1(w);
        vec h2(d);
        mat fie(d,vec(w,0));
        rep(i,w) cin >> h1[i];
        rep(i,d) cin >> h2[i];   

        rep(i,w)rep(j,d)if(h1[i] == h2[j]){
            h2[j] = 0;
            break;
        }
        
        int ans = 0;
        rep(i,w)ans += h1[i];
        rep(i,d)ans += h2[i];;
        cout << ans << endl;
    }
}
