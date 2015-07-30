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
    int n, m;
    while(cin>>n>>m,n||m){
        vector<pair<int,pair<int,int> > > data;
        rep(i,m){
            int t, s, d;
            cin >> t >> s >> d;
            data.pb(mp(t,mp(s,d)));
        }
        bool p[20001] = {false};
        p[1] = true;
        int ans = 1;
        sort(all(data));
        rep(i,m){
            if(p[data[i].second.first] && !p[data[i].second.second]){
                ans++;
                p[data[i].second.second] = true;
            } 
        }
        cout << ans << endl;
    }
}
