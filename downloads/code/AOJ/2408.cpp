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
typedef pair<int,int> pii;

int main(){
    int n, k;
    cin >> n >> k;
    vector<set<int> > boat(k);
    rep(i,k){
        int m;
        cin >> m;
        rep(j,m){
            int t;
            cin >> t;
            boat[i].insert(t);
        }
    }
    int r;
    cin >> r;
    bool bunny[51] = {false};
    rep(i,r){
        int p, q;
        cin >> p >> q;
        rep(j,k){
            if(boat[j].find(p) != boat[j].end() && boat[j].find(q) != boat[j].end()){
                bunny[p] = true;
                bunny[q] = true;
                break;
            }
        }
    }
    int ans = 0;
    rep(i,n+1) if(bunny[i]) ans++;
    cout << ans << endl;
}
