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

int w, h;

bool num(char ch){
    return (ch >= '0' && ch <= '9');
}

string maxs(string a, string b){
    while(a[0]=='0') a.erase(a.begin());
    while(b[0]=='0') b.erase(b.begin());
    if(a.size()>b.size()) return a;
    if(a.size()<b.size()) return b;
    rep(i,a.size()){
        if(a[i] > b[i]) return a;
        if(a[i] < b[i]) return b;
    }
    return a;
}

int main(){
    while(cin>>w>>h,w||h){
        vector<string> m(h);
        vector<vector<string> > dp(h,vector<string>(w,""));
        rep(i,h) cin >> m[i];
        string ans;
        repd(i,h-1,-1)repd(j,w-1,-1)if(num(m[i][j])){
            dp[i][j].pb(m[i][j]);
            if(i+1<h && num(m[i+1][j]) && j+1<w && num(m[i][j+1])){
                if(dp[i+1][j].size() > dp[i][j+1].size()){
                    dp[i][j] += dp[i+1][j];
                }else if(dp[i+1][j].size() < dp[i][j+1].size()){
                    dp[i][j] += dp[i][j+1];
                }else {
                    bool flag = true;
                    rep(k,dp[i+1][j].size()){
                        if(dp[i+1][j][k] > dp[i][j+1][k]) break;
                        else if(dp[i+1][j][k] < dp[i][j+1][k]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag) dp[i][j] += dp[i+1][j];
                    else dp[i][j] += dp[i][j+1];
                }
            }else if(i+1<h && num(m[i+1][j])) dp[i][j] += dp[i+1][j];
            else if(j+1<w && num(m[i][j+1])) dp[i][j] += dp[i][j+1];

            ans = maxs(ans, dp[i][j]);
        }
        cout << ans << endl;
    }
}
