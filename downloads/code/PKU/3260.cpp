#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

const int M = 20000;
int N, T, V[128], C[128];
int change[20010], pay[20010];
pii deq[20010];

int main(){
    scanf("%d%d", &N, &T);
    for(int i = 0; i < N; i++)
        scanf("%d", V+i);
    for(int i = 0; i < N; i++)
        scanf("%d", C+i);

    for(int i = 0; i < N; i++)
        for(int j = V[i]; j <= M; j++)
            if(change[j-V[i]] or j == V[i])
                change[j] = change[j] > 0? min(change[j], change[j-V[i]]+1): change[j-V[i]]+1;

    for(int i = 0; i < N; i++){
        int num = C[i];
        for(int j = 1; num > 0; j<<=1){
            int mul = min(num, j);
            num -= mul;
            for(int k = M; k - mul*V[i] >= 0; k--)
                if(k-mul*V[i] == 0 or pay[k-mul*V[i]] > 0)
                    pay[k] = pay[k] > 0? min(pay[k], pay[k-mul*V[i]]+mul): pay[k-mul*V[i]]+mul;
        }
    }
    int ans = int(1e9);
    for(int i = T; i <= M; i++)
        if(pay[i] and (change[i-T] or i == T))
            ans = min(ans, pay[i] + change[i-T]);
    if(ans == int(1e9)) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}
