#include <iostream>
#include <vector>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repd(i, a, b) for(int i = a; i > b; i--)

typedef long long ll;

using namespace std;

ll dp[10][1001] = {0};

int main(){
    dp[0][0] = 1;
    rep(i, 101){
        repd(j, 1000, -1){
            repd(k, 9, 0){
                if(j - i >= 0)dp[k][j] += dp[k-1][j - i];
            }
        }
    }
    int n, s;
    while(cin >> n >> s, n){        
        cout << dp[n][s] << endl;
    }
}