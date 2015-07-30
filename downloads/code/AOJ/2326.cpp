#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
int A, B, P, dp[100010];
inline void add(int &a, int b){ a=(a+b)%P;}
inline void sub(int &a, int b){ a=(a-b+P)%P;}
inline int f(int n){
    int c = 0;
    while(n > 0) { n/=10; c++;}
    return pow(10,c-1);
}

void calc(int n){
    int gv = dp[n-A], m = n;
    while(m < B){
        add(dp[m-A+(m==n)],gv);
        m *= 10;
        sub(dp[min(f(m),B)-A],gv);
    }
}

int solve(){
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    int ans = 0; B++;
    repi(i,A,B){
        if(i>A) add(dp[i-A],dp[i-A-1]);
        calc(i);
        add(ans,dp[i-A]);
    }
    return ans;
}

signed main(){
    while(cin >> A >> B >> P, A|B|P)
        cout << solve() << endl;
    return 0;
}


