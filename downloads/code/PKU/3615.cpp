#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

int N, M, T;
int H[310][310];

int main(){
    scanf("%d%d%d", &N, &M, &T);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            H[i][j] = int(1e9);
    
    for(int i = 0; i < M; i ++){
        int a, b, h;
        scanf("%d%d%d", &a, &b, &h);
        a--; b--;
        H[a][b] = h;
    }
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                H[i][j] = min(H[i][j], max(H[i][k], H[k][j]));
    
    while(T--){
        int s, t;
        scanf("%d%d", &s, &t);
        s--; t--;
        if(H[s][t] == int(1e9)) puts("-1");
        else printf("%d\n", H[s][t]);
    }
    return 0;
}
