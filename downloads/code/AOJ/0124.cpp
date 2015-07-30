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
    bool flag = true;
    while(cin >> n, n){
        vector<P> p;
        vector<string> s;
        rep(i,n){
            int a, b, c;
            string str;
            cin >> str >> a >> b >> c;
            p.pb(mp(a*3+c,n-i-1));
            s.pb(str);
        }
        sort(p.rbegin(),p.rend());
        if(flag) flag = false;
        else cout << endl;
        rep(i,n) cout << s[n-p[i].second-1] << ',' << p[i].first << endl;
    }
}
