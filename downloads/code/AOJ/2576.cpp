#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
int D, N, sc, dp[16];
string s;

int main(){
    cin >> D;
    rep(i,2){
        cin >> N;
        while(N--){
            cin >> s >> sc;
            if(s == "D" or s == "DD")
                for(int j = D-i-1; j >= 0; j--)
                    dp[j+i+1] = max(dp[j+i+1], dp[j]+sc);
        }
    }
    cout << dp[D] << endl;
    return 0;
}


