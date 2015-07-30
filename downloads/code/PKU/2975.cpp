#include <cstdio>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;

int n, k[1024];

int solve(){
    int ans = 0, x = 0;
    rep(i,n) x ^= k[i];
    if(!x) return x;
    int pos = -1;
    while(x){
        x >>= 1;
        pos++;
    }
    rep(i,n)if( (1 << pos) & k[i]) ans++;
    return ans;
}

int main(){
    while(scanf("%d", &n), n){
        rep(i,n) scanf("%d", k+i);
        printf("%d\n", solve());
    }
    return 0;
}
