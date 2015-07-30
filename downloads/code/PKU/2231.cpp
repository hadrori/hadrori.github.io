#include <algorithm>
#include <cstdio>

using namespace std;

#define int long long

int N;
int d[10010];

signed main(){
    scanf("%lld", &N);
    for(int i = 0; i < N; i++)
        scanf("%lld", d+i);
    sort(d, d+N);
    
    int ans = 0;
    for(int i = 0; i < N; i++)
        ans += (-2*(N-1-i) + 2*i) * d[i];
    printf("%lld\n", ans);
    return 0;
}
