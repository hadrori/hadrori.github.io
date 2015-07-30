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

int main(){
    int n;
    while(cin>>n,n){
        vector<vector<P> > b;
        vector<vector<P> > pl;
        vector<P> v, u;
        int m, px, py, fm;
        cin >> m >> px >> py;
        fm = m;
        rep(j,m-1){
            int x, y;
            cin >> x >> y;
            v.pb(mp(x-px,y-py));
            u.pb(mp(px-x,py-y));
            px = x;
            py = y;
        }
        b.pb(v);
        reverse(all(u));
        b.pb(u);
        rep(i,3){
            rep(j,v.size()){
                int tmp = v[j].first;
                v[j].first = -v[j].second;
                v[j].second = tmp;
                tmp = u[j].first;
                u[j].first = -u[j].second;
                u[j].second = tmp;
            }
            b.pb(v);
            b.pb(u);
        }
        rep(i,n){
            vector<P> p;
            cin >> m >> px >> py;
            rep(j,m-1){
                int x, y;
                cin >> x >> y;
                p.pb(mp(x-px,y-py));
                px = x;
                py = y;
            }

            rep(j,8){
                bool ok = (fm == m);
                rep(k,p.size()){
                    if(b[j][k].first != p[k].first || b[j][k].second != p[k].second){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    cout << i + 1 << endl;
                    break;
                }
            }
        }

    
    
        cout << "+++++\n";
    }
}
