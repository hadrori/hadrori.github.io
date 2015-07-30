#include <algorithm>
#include <cstdio>

using namespace std;

int N, S;
int len[20010];

int main(){
    scanf("%d%d", &N, &S);
    for(int i = 0; i < N; i++)
        scanf("%d", len+i);
    sort(len, len+N);

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(len[i] > S / 2) break;
        ans += upper_bound(len+i+1, len+N, S-len[i]) - len - i - 1;
    }
    printf("%d\n", ans);
    return 0;
}
