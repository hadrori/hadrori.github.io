#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

int N;
int E[32][32];
bool dist[32][2048];
bool used[32];
vector<int> gcds;
long long ans;

long long gcd(long long a, long long b){
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void dfs(int v, int g){
    if(dist[v][g]) return;
    dist[v][g] = 1;
    if(v == 1) {
        ans *= g / gcd(ans,g);
        return;
    }
    for(int i = 1; i < N; i++)
        if(E[v][i] and !used[i]){
            used[i] = 1;
            dfs(i, gcd(g, E[v][i]));
            used[i] = 0;
        }
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &E[i][j]);

    for(int i = 0; i < 2048; i++)
        dist[0][i] = 1;
    
    ans = 1;
    for(int i = 1; i < N; i++)
        if(E[0][i]){
            used[i] = 1;
            dfs(i, E[0][i]);
            used[i] = 0;
        }

    printf("%lld\n", ans);
    return 0;
}
