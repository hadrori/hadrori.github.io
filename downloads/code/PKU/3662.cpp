#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

struct S{
    int x, cst, k;
    S(int x, int cst, int k):x(x),cst(cst),k(k){}
    bool operator<(const S &s) const{ return cst > s.cst;}
};

const int inf = int(1e9);
int N, P, K;
vector<pii> edge[1024];
int mlen[1024][1024];

int main(){
    scanf("%d%d%d", &N, &P, &K);
    for(int i = 0; i < P; i++){
        int a, b, l;
        scanf("%d%d%d", &a, &b, &l);
        a--; b--;
        edge[a].push_back(pii(b,l));
        edge[b].push_back(pii(a,l));
    }
    memset(mlen, -1, sizeof(mlen));
    priority_queue<S> que;
    que.push(S(0,0,0));
    while(!que.empty()){
        S s = que.top(); que.pop();
        if(mlen[s.x][s.k] >= 0) continue;
        mlen[s.x][s.k] = s.cst;
        for(int i = 0; i < edge[s.x].size(); i++){
            pii &e = edge[s.x][i];
            que.push(S(e.first, max(s.cst, e.second), s.k));
            if(s.k < K) que.push(S(e.first, s.cst, s.k+1));
        }
    }
    int ans = inf;
    for(int i = 0; i <= K; i++)
        if(mlen[N-1][i] >= 0) ans = min(ans, mlen[N-1][i]);
    if(ans == inf) ans = -1;
    printf("%d\n", ans);
    return 0;
}
