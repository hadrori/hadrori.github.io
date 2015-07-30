#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int N, B;
int H[20010];
int ans;

void dfs(int i, int sum){
    if(sum >= B) {
        ans = min(ans, sum);
        return;
    }
    if(i == N) return;
    dfs(i+1, sum);
    dfs(i+1, sum+H[i]);
}

int main(){
    scanf("%d%d", &N, &B);
    for(int i = 0; i < N; i++)
        scanf("%d", H+i);
    sort(H, H+N);
    ans = 1e9;
    dfs(0, 0);
    printf("%d\n", ans-B);
    return 0;
}
