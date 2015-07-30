#include <cstdio>

using namespace std;

int N;
int H[50010];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", H+i);

    bool up = 1;
    int tail = 0;
    for(int i = 1; i < N; i++){
        if(up && H[i-1] < H[i]) continue;
        if(!up && H[i-1] > H[i]) continue;
        if(up) printf("%d\n", i);
        if(up && H[i-1] == H[i]) up = 0;
        up ^= 1;
    }
    if(up) printf("%d\n", N);
    return 0;
}
