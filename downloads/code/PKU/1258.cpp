#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

int N;
int E[128][128];
bool used[128];

int main(){
    while(~scanf("%d", &N)){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                scanf("%d", &E[i][j]);
        
        int ans = 0;
        memset(used,0,sizeof(used));
        priority_queue<pii, vector<pii>, greater<pii> > que;
        que.push(pii(0,0));
        
        while(!que.empty()){
            int v = que.top().second, c = que.top().first;
            que.pop(); 
            if(used[v]) continue;
            used[v] = 1;
            ans += c;
            for(int i = 0; i < N; i++)
                if(!used[i]) que.push(pii(E[v][i], i));
        }
        printf("%d\n", ans);
    }
    return 0;
}
