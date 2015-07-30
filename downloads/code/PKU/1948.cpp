#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const double eps = 1e-8;

inline bool isTri(int i, int j, int k){ return (i + j > k) && (j + k > i) && (k + i > j);}

inline double area(int i, int j, int k){
    double s = 1. * (i + j + k) / 2;
    return sqrt(s*(s-i)*(s-j)*(s-k));
}
int N, L[64], sum;
bool dp[2048][2048];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", L+i);
    
    dp[0][0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = sum; j >= 0; j--)
            for(int k = sum - j; k >= 0; k--){
                dp[j][k+L[i]] |= dp[j][k];
                dp[j+L[i]][k] |= dp[j][k];
            }
        sum += L[i];
    }

    int ans = -1;
    for(int i = 1; i < sum; i++)
        for(int j = i; i + j < sum; j++)
            if(dp[i][j]) {
                int k = sum - i - j;
                if(isTri(i, j, k)) ans = max(ans, int(100 * area(i, j, k)));
            }
    
    printf("%d\n", ans);
    return 0;
}
