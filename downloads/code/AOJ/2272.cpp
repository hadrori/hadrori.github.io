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

using namespace std;
int semi[60][60];
int h, w;

void ston(string str, int i){
    rep(j,w) semi[i][j] = str[j] - '0';
}

int main(){
    cin >> h >> w;
    string str;
    rep(i,h){
        cin >> str;
        ston(str,i);
    }

    int dp[60][60] = {0};
    rep(i,h)rep(j,w){
        if(!i && j) dp[i][j] = dp[i][j-1] + semi[i][j];
        if(!j && i) dp[i][j] = dp[i-1][j] + semi[i][j];
        if(i && j)dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + semi[i][j];
    }
    cout << dp[h-1][w-1] << endl;
}
