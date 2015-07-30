#include <bits/stdc++.h>
using namespace std;

int dp[8][4096], n;

int main()
{
        for (int i = 0; i <= 1000; i++) dp[1][i] = 1;
        for (int i = 1; i < 3; i++)
                for (int j = 0; j <= 1000*i; j++)
                        for (int k = 0; k <= 1000*i; k++)
                                dp[i*2][j+k] += dp[i][j]*dp[i][k];
        
        while(cin >> n) cout << dp[4][n] << endl;
        return 0;
}
