#include <algorithm>
#include <cstdio>

using namespace std;

int N, D, ans, cnt[30010];

int main(){
    scanf("%d", &N);
    ans = N + 1;
    for(int i = 0; i < N; i++){
        scanf("%d", &D);
        cnt[i+1] = cnt[i] + D % 2;
    }
    for(int i = 0; i <= N; i++)
        ans = min(ans, cnt[N] + i - 2*cnt[i]);
    printf("%d\n", ans);
    return 0;
}
