#include <cstdio>

#define int long long
using namespace std;

int N, h, top, ans;
int st[80010];

signed main(){
    scanf("%lld", &N);
    while(N--){
        scanf("%lld", &h);
        while(top > 0 and st[top-1] <= h) top--;
        ans += top;
        st[top++] = h;
    }
    printf("%lld\n", ans);
    return 0;
}
