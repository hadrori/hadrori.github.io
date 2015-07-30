#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define rep(i,a) for(int i = 0; i < a; i++)
#define repi(i,a,b) for(int i = a; i < b; i++)
#define repd(i,a,b) for(int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int> > trs;
    vector<int> trsx;
    rep(i,n){
        int x, y;
        cin >> x >> y;
        trs.pb(mp(x,y));
        trsx.pb(x);
    }
    sort(trs.begin(),trs.end());
    sort(trsx.begin(),trsx.end());
    rep(z,m){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        vector<int>::iterator itr1 = lb(trsx.begin(), trsx.end(), x1);
        vector<int>::iterator itr2 = ub(trsx.begin(), trsx.end(), x2);

        int ans = 0;
        for(int i = itr1 - trsx.begin(); i < itr2 - trsx.begin(); i++){
            if(trs[i].second >= y1 && trs[i].second <= y2)  ans++;
        }
        cout << ans << endl;
    }
}
