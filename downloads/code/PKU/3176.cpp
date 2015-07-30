#include <algorithm>
#include <cstdio>

using namespace std;

int N;
int score[360][360];
int point[360][360];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
            scanf("%d", &point[i][j]);
    score[0][0] = point[0][0];
    for(int i = 0; i < N-1; i++)
        for(int j = 0; j <= i; j++){
            score[i+1][j+1] = max(score[i+1][j+1], score[i][j] + point[i+1][j+1]);
            score[i+1][j] = max(score[i+1][j], score[i][j] + point[i+1][j]);
        }
    int ans = 0;
    for(int i = 0; i < N; i++)
        ans = max(ans, score[N-1][i]);
    printf("%d\n", ans);
    return 0;
}
