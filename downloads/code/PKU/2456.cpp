#include <algorithm>
#include <cstdio>

using namespace std;

const int inf = int(1e9);

int N, C, x[100010];

bool can(int d){
    int prev = 0;
    for(int i = 1; i < C; i++){
        int pos = prev+1;
        while(pos < N && x[pos] - x[prev] < d) pos++;
        if(pos == N) return 0;
        prev = pos;
    }
    return 1;
}

int main(){
    scanf("%d%d", &N, &C);
    for(int i = 0; i < N; i++)
        scanf("%d", x+i);
    sort(x, x+N);

    int lb = -1, ub = inf+1;
    while(ub - lb > 1){
        int mid = (lb + ub) / 2;
        if(can(mid)) lb = mid;
        else ub = mid;
    }
    printf("%d\n", lb);
    return 0;
}
