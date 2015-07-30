#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define rep(i,a) for(int i = 0; i < a; i++)
#define repd(i,a,b) for(int i = a; i > b; i--)
#define pb push_back
#define INF 10000000

int main(){
    string str;
    while(getline(cin,str)){
        vector<int> r;
        stringstream s(str);
        int n = 0, w;
        s >> w;
        while(!s.eof()){
            int t;
            s >> t;
            r.pb(t);
            n++;
        }
        vector<vector<double> > dp(1<<n,vector<double> (n,INF));
        rep(i,n) dp[(1<<n)-1-(1<<i)][i] = r[i];

        repd(i,(1<<n)-2,-1) rep(j,n){
            if(!(i&(1<<j))){
                rep(k,n) {
                    dp[i][j] = min(dp[i][j],dp[i|(1<<j)][k]+2*sqrt(r[j]*r[k]));
                }
            }
        }
        double ans = INF;
        rep(i,n) ans = min(ans,dp[0][i]+r[i]);
        cout << ((ans <= w)? "OK": "NA") << endl;
    }
}
