class PalindromicSubstringsDiv1 {
public:
    double expectedPalindromes( vector <string> S1, vector <string> S2 ) {
        string S ="";
        rep(i,S1.size()) S += S1[i];
        rep(i,S2.size()) S += S2[i];
        double dp[5010][5010] = {};
        int n = S.size();
        for(int i = 0; i < n; i++)
            dp[i][i] = dp[i+1][i] = 1.0;
        double ans = n;
        for(int w = 2; w <= n; w++)
            for(int l = 0; l + w <= n; l++){
                int r = l + w - 1;
                if(S[l] != '?' && S[l] == S[r])
                    dp[l][r] = dp[l+1][r-1];
                else if(S[l] == '?' || S[r] == '?')
                    dp[l][r] = dp[l+1][r-1] / 26;
                ans += dp[l][r];
            }
        return ans;
    }
};
