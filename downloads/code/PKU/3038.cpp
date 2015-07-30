#include <cstdio>
#include <queue>
#include <vector>
#include <map>

using namespace std;
typedef pair<int,int> pii;
int K, N, C, ans;

int main(){
    scanf("%d%d%d", &K, &N, &C);
    priority_queue<pii> que[2];
    for(int i = 0; i < K; i++){
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        a--; b--;
        if(a < b) que[0].push(pii(b, a));
        else que[1].push(pii(N-b-1, N-a-1));
    }
    for(int i = 0; i < 2; i++){
        while(!que[i].empty()){
            int from = que[i].top().second, to = que[i].top().first;
            que[i].pop();
            int can;
            /*
              can = max [from, to]
             */
            ans += can;
            /*
              update 
             */
        }
    }
    printf("%d\n", ans);
    return 0;
}
