#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define INF 1e8
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;

int main(){
    int n, w, d;
    while(cin>>n>>w>>d,n||w||d){
        vector<P> rect;
        vi area;
        rect.pb(mp(w,d));
        area.pb(w*d);
        rep(i,n){
            int id, len;
            cin >> id >> len;
            id--;
            w = rect[id].first;
            d = rect[id].second;
            rect.erase(rect.begin()+id);
            area.erase(area.begin()+id);
            len %= (w + d);
            if(len < w){
                int minw = min(w-len, len);
                rect.pb(mp(minw, d));
                area.pb(minw*d);
                rect.pb(mp(w-minw, d));
                area.pb((w-minw)*d);
            }else{
                int mind = min(len-w, w+d-len);
                rect.pb(mp(w, mind));
                area.pb(w*mind);
                rect.pb(mp(w, d-mind));
                area.pb(w*(d-mind));
            }
        }
        sort(all(area));
        rep(i,n+1) cout << area[i] << ((i==n)? '\n': ' ');
    }
}
