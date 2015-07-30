#include <algorithm>
#include <cstdio>

using namespace std;

int N, B;
int H[20010];

int main(){
    scanf("%d%d", &N, &B);
    for(int i = 0; i < N; i++)
        scanf("%d", H+i);
    sort(H, H+N);
    int ans = 0;
    while(B > 0) B -= H[N-(ans++)-1];
    printf("%d\n", ans);
    return 0;
}
