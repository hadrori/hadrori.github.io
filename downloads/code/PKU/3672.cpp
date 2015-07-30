#include <cstdio>

using namespace std;

int M, T, U, F, D;

int main(){
    scanf("%d%d%d%d%d", &M, &T, &U, &F, &D);
    int ans = 0;
    while(T --> 0){
        char c; scanf(" %c\n", &c);
        if(c == 'f') M -= 2 * F;
        else if(c == 'u' || c == 'd') M -= U + D;
        if(M < 0) break;
        ans++;
    }
    printf("%d\n", ans);
}
