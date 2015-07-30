#include <cstdio>

using namespace std;

const int mod = int(1e9);
int N;
int dp[1000010];

int main(){
    scanf("%d", &N);
    dp[0] = 1;
    for(int i = 1; i <= N; i <<= 1)
        for(int j = 0; j + i <= N; j++)
            dp[i+j] = (dp[i+j] + dp[j]) % mod;
    printf("%d\n", dp[N]);
    return 0;
}
