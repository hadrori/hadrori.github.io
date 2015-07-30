#include <cstdio>

using namespace std;

const int mod = int(1e9);
int N;
int dp[1000010];

int main(){
    scanf("%d", &N);
    dp[0] = 1;
    for(int i = 1; i <= N; i++){
        if(i % 2 == 0) dp[i] += dp[i / 2];
        dp[i] += dp[i-1];
        dp[i] %= mod;
    }
    printf("%d\n", dp[N]);
    return 0;
}
