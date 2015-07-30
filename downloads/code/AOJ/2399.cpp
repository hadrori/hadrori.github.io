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
#define lb lower_bound
#define ub upper_bound
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

int n, k;
vi know[128];
vi l;

void init(){
    rep(i,128) know[i].clear();
    l.clear();
    return;
}
void input(){
    rep(i,n){
	int m;
	cin >> m;
	while(m--){
	    int a;
	    cin >> a;
	    a--;
	    know[i].pb(a);
	}
    }
    cin >> k;
    rep(_,k){
	int a;
	cin >> a;
	a--;
	l.pb(a);
    }
    return;
}
void solve(){
    int ans = -1;
    rep(i,n){
	int cnt = 0;
	rep(j,k){
	    rep(a,know[i].size()){
		if(know[i][a] == l[j]){
		    cnt++;
		    break;
		}
	    }
	}
	if(cnt == k && ans >= 0){
	    cout << -1 << endl;
	    return;
	}
	if(cnt == k){
	    ans = i;
	}
    }
    if(ans < 0) cout << -1 << endl;
    else cout << ++ans << endl;
    return;
}

int main(){
    while(cin >> n, n){
	init();
	input();
	solve();
    }
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector<set<int> > info(n+1);
        rep(i,n){
            int m;
            cin >> m;
            rep(j,m){
                int t;
                cin >> t;
                info[t].insert(i+1);
            }
        }
        set<int> ans;
        int k;
        cin >> k;
        rep(i,k){
            set<int> tmp;
            int l;
            cin >> l;
            if(i==0){
                set_union(ans.begin(),ans.end(),info[l].begin(),info[l].end(), inserter(tmp, tmp.begin()));
                ans.swap(tmp);
            }else{
                set_intersection(ans.begin(),ans.end(),info[l].begin(),info[l].end(), inserter(tmp, tmp.begin()));
                ans.swap(tmp);
            }
        }
        if(ans.size() == 1) cout << *ans.begin() << endl;
        else cout << -1 << endl;
    }
    
}
*/
