#include <cstdio>

using namespace std;

const int base = 10000;
int N;
int xs[20010], ys[20010];
int xsum[20010], ysum[20010];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int x, y; scanf("%d%d", &x, &y);
        xs[x+base]++; ys[y+base]++;
    }
    for(int i = 0; i <= 20000; i++){
        xsum[i+1] = xsum[i] + i*xs[i];
    }
    return 0;
}
