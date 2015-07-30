#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int,int> pii;
int seq[1024];
int n, m;
double dp[1024][1024];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> seq[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dp[i][j] = (seq[i] > seq[j]);

    while(m--){
        int a, b; cin >> a >> b;
        a--; b--;
        dp[a][b] = dp[b][a] = .5;
        for(int i = 0; i < n; i++){
            if(i == a or i == b) continue;
            dp[i][a] = dp[i][b] = (dp[i][a]+dp[i][b]) * .5;
            dp[a][i] = dp[b][i] = (dp[a][i]+dp[b][i]) * .5;
        }
    }
    double ans = 0.;
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            ans += dp[i][j];
    printf("%.8f\n", ans);
    return 0;
}
