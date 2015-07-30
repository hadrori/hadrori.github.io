#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int N, K, P, M;
int pos[100010];
int ans[100010];

int main(){
    scanf("%d%d%d", &N, &K, &P);
    M = K / N;
    queue<int> deck;
    for(int i = 1; i <= K; i++)
        deck.push(i);
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(j == N-1) ans[i] = deck.front();
            deck.pop();
            for(int k = 0; k < P; k++){
                deck.push(deck.front());
                deck.pop();
            }
        }
    }
    sort(ans, ans+M);
    for(int i = 0; i < M; i++)
        printf("%d\n", ans[i]);
    return 0;
}
