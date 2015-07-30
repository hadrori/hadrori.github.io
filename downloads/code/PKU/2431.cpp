#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

typedef pair<int,int> pii;

int N, L, P;
pii stand[10010];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int x, f; scanf("%d%d", &x, &f);
        stand[i] = pii(-x, f);
    }
    stand[N++] = pii(0,0);
    scanf("%d%d", &L, &P);
    sort(stand, stand+N);
    priority_queue<int> fuel;
    int ans = 0;
    for(int i = 0; i < N; i++){
        int x = -stand[i].first;
        int need = L - x;
        while(P < need and !fuel.empty()){
            P += fuel.top(); fuel.pop();
            ans++;
        }
        if(P < need){
            ans = -1;
            break;
        }
        L = x;
        P -= need;
        fuel.push(stand[i].second);
    }
    printf("%d\n", ans);
    return 0;
}
