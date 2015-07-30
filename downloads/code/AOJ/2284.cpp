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

typedef long long ll;
#define P pair<int,int>

using namespace std;

int main(){
    int w, h;
    while(cin >> w >> h, w || h){
        string str;
        int last = 0;
        vector<vector<P> > seal(2510);
        P g;
        rep(i,h) rep(j,w){
            string str;
            cin >> str;
            if(str[0] == 'S') seal[0].pb(P(i,j));
            else if(str[0] == 'G') g = P(i,j);
            else if(str[0] == '.');
            else {
                int n = 0;
                rep(k,str.size()){
                    n *= 10;
                    n += str[k] - '0';
                }
                last = max(last,n);
                seal[n].pb(P(i,j));
            }
        }
        seal[last+1].pb(g);
        vector<vector<int> > dp(last+2);
        rep(i,last+2)dp[i] = vector<int> (seal[i].size(),10000000);
        dp[0][0] = 0;
        repi(i,1,last+2) rep(j,seal[i].size()){
            rep(k,seal[i-1].size()){
                dp[i][j] = min(dp[i][j],dp[i-1][k] + abs(seal[i-1][k].first - seal[i][j].first) + abs(seal[i-1][k].second - seal[i][j].second));
            }
        }
        cout << dp[last+1][0] << endl;
    }
}
