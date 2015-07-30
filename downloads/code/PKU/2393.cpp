#include <algorithm>
#include <cstdio>

using namespace std;

int N, S, C, Y, P;
//int C[10010], Y[10010];

int main(){
    scanf("%d%d", &N, &S);

    P = int(1e9);
    long long ans = 0;
    for(int i = 0; i < N; i++){
        scanf("%d%d", &C, &Y);
        P = min(P + S, C);
        ans += P * Y;
    }
    printf("%lld\n", ans);
    return 0;
}
