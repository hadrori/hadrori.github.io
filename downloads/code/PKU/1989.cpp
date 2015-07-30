#include <cstdio>
#include <cstring>

using namespace std;

int N, K;
int seq[100010];
bool used[10010];

int main(){
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%d", seq+i);
        seq[i]--;
    }
    int ans = 0, cnt = 0;
    for(int i = 0; i < N; i++){
        if(!used[seq[i]]) {
            used[seq[i]] = 1;
            cnt++;
        }
        if(cnt == K) {
            ans++;
            cnt = 0;
            memset(used, 0, sizeof(used));
        }
    }
    printf("%d\n", ans+1);
    return 0;
}
