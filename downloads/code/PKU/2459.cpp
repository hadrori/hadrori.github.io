#include <cstdio>

using namespace std;

int C, F1, F2, D, diff;
int cows[2048];

int main(){
    scanf("%d%d%d%d", &C, &F1, &F2, &D);
    diff = F1 - F2;
    for(int i = 0; i < C; i++){
        int s, t;
        scanf("%d%d", &s, &t);
        for(int j = s; j <= t; j++) cows[j]++;
    }
    int cur = D, sum = 0;
    while(1){
        sum += cows[cur];
        if(sum == diff) break;
        cur--;
    }
    printf("%d\n",cur);
    return 0;
}
