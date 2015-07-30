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
    int n;
    while(cin>>n,n){
        int w, h;
        cin >> w >> h;
        vector<vector<bool> > tr(h,(vector<bool>(w,false)));
        while(n--){
            int a, b;
            cin >> a >> b;
            tr[b-1][a-1] = true;
        }
        int s, t;
        cin >> s >> t;
        int ans = 0;

        rep(i,h-t+1)rep(j,w-s+1){
            int cnt = 0;
            rep(a,t)rep(b,s){
                if(tr[i+a][j+b]) cnt++;
            }
            ans = max(ans, cnt);
        }

        cout << ans << endl;
    }
}
