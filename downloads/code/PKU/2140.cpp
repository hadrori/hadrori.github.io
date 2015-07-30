#include <cstdio>

using namespace std;

int N, ans;

int main(){
    scanf("%d", &N);
    int l = 1, r = 2, sum = 1;
    while(l <= N){
        if(sum == N){
            ans++;
            sum -= l;
            l++;
        }
        else if(sum < N){
            sum += r;
            r++;
        }
        else {
            sum -= l;
            l++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
