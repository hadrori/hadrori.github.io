#include <cmath>
#include <cstdio>

using namespace std;

int N, K;
int S, T, R;

int main(){
    scanf("%d%d", &N, &K);
    for(int i = 0; i < K; i++){
        scanf("%d%d%d", &S, &T, &R);
        int res = N, ans = 0;
        int t = N / (S * T);
        ans = t * (T + R);
        res -= t * S * T;
        if(res == 0) ans -= R;
        else ans += ceil(1.0*res / S);
        printf("%d\n", ans);
    }
    return 0;
}
