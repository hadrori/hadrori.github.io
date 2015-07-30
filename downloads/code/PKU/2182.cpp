#include <cstdio>

using namespace std;

int N;
int seq[8010];
int ans[8010];

int main(){
    scanf("%d", &N);
    for(int i = 1; i < N; i++)
        scanf("%d", seq+i);
    for(int i = 1; i <= N; i++){
        int cnt = i - 1;
        for(int j = N-1; j >= 0; j--)
            if(seq[j] == cnt) ans[j] = i;
            else if(ans[j] > 0) cnt--;
    }
    for(int i = 0; i < N; i++)
        printf("%d\n", ans[i]);
    return 0;
}
