#include <algorithm>
#include <cstdio>

using namespace std;

int N, P, C;
int fence[1024];

int main(){
    scanf("%d%d%d", &N, &P, &C);
    for(int i = 0; i < N; i++){
        int t; scanf("%d", &t);
        fence[t-1]++;
    }
    int ans = 0;
    for(int l = 0; l < P; l++){
        int r = l;
        int cnt = 0;
        while(cnt + fence[r] <= C && r < P-1){
            cnt += fence[r];
            r++;
        }
        ans = max(ans, r - l);
    }
    printf("%d\n", ans);
    return 0;
}
