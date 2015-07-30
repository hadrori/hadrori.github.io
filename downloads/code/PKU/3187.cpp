#include <algorithm>
#include <cstdio>

using namespace std;

int N, res;
int seq[16];
int combm[16][16];
int comb(int n, int k){
    if(combm[n][k] > 0) return combm[n][k];
    int ret = 1;
    for(int i = 0; i < k; i++) ret *= n - i;
    for(int i = 0; i < k; i++) ret /= i + 1;
    return combm[n][k] = ret;
}

int main(){
    scanf("%d%d", &N, &res);
    for(int i = 0; i < N; i++) seq[i] = i+1;
    do{
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum += comb(N-1, i) * seq[i];
        if(sum == res) break;
    }while(next_permutation(seq, seq+N));

    for(int i = 0; i < N-1; i++)
        printf("%d ", seq[i]);
    printf("%d\n", seq[N-1]);
    return 0;
}
