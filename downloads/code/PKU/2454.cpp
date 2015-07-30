#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

typedef pair<int,int> pii;

int K, border;
pii cows[256];

int main(){
    scanf("%d", &K);
    border = K*1000/2;
    for(int i = 0; i < 3*K; i++){
        int c; scanf("%d", &c);
        cows[i] = pii(c,i+1);
    }
    sort(cows, cows+3*K);

    int sum[2] = {0};
    pii seq[3][64];
    for(int i = 0; i < K; i++){
        seq[0][i] = cows[K+i];
        seq[1][i] = cows[2*K+i];
        seq[2][i] = cows[i];
        sum[0] += cows[K+i].first;
        sum[1] += cows[2*K+i].first; 
    }
    while(sum[0] <= border or sum[1] <= border){
        int p = rand() % K;
        int q = rand() % K;
        sum[0] += seq[1][q].first - seq[0][p].first;
        sum[1] += seq[0][p].first - seq[1][q].first;
        swap(seq[0][p],seq[1][q]);
    }
    
    for(int j = 0; j < 3; j++)
        for(int i = 0; i < K; i++)
            printf("%d\n", seq[j][i].second);
    return 0;
}
