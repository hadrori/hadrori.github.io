#include <algorithm>
#include <cstdio>

using namespace std;

#define int long long

const int inf = (int)1e18;
int N, F;
int field[100010];
int sum[100010];
int M[300010];

bool can(int x){
    sum[0] = 0; M[N+1] = -inf;
    for(int i = 0; i < N; i++){
        sum[i+1] = sum[i] + field[i] - x;
        M[i*2+1] = -inf;
        M[i*2] = -inf;
    }
    for(int i = N; i >= 0; i--)
        M[i] = max(M[i+1], sum[i]);
    
    for(int i = 0; i < N; i++)
        if(M[i+F]-sum[i] >= 0) return 1;
    return 0;
}

signed main(){
    scanf("%lld%lld", &N, &F);
    for(int i = 0; i < N; i++){
        scanf("%lld", field+i);
        field[i] *= 1000;
    }
    int lb = 0, ub = 1000*2000+1000;
    while(ub - lb > 1){
        int mid = (lb + ub) / 2;
        if(can(mid)) lb = mid;
        else ub = mid;
    }
    printf("%lld\n", lb);
    return 0;
}
