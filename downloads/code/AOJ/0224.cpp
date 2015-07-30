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

#define INF 100000000

int main(){
    int m, n, k, d;
    while(cin>>m>>n>>k>>d,m||n||k||d){
        vector<int> cal(m);
        rep(i,m)cin>>cal[i];

        vector<P> w(m+n+2);
        rep(i,d){
            string s;
            int a[3];
            rep(i,2){
                cin >> s;
                if(s[0]=='H') a[i] = 0;
                else if(s[0]=='C'){
                    a[i] = s[1] - '0';
                }else if(s[0]=='L'){
                    a[i] = 1 + m + s[1] - '0';
                }else if(s[0]=='D') a[i] = m + n + 1;
            }
            cin >> a[2];
            int t = -a[2] * k;
            if(a[1] > 0 && a[1] <= m) t += cal[a[1]-1];
            w[a[0]].pb(P(a[1],t));
        }
    }
}
