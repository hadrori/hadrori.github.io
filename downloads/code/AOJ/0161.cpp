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
    while(cin >> n, n){
        vector<P> d;
        rep(i,n){
            int id, m, s;
            cin >> id;
            int sum = 0;
            rep(j,4){
                cin >> m >> s;
                sum += m*60+s;
            }
            d.pb(P(sum,id));
        }
        sort(d.begin(),d.end());
        cout << d[0].second << endl << d[1].second << endl << d[n-2].second << endl;
    }
}
