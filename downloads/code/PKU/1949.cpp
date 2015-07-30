#include <cstdio>
#include <vector>

using namespace std;

int N, tim[10010];
int done[10010];
vector<int> P[10010];

int rec(int i){
    if(done[i]) return done[i];
    done[i] = tim[i];
    for(int j = 0; j < P[i].size(); j++)
        done[i] = max(rec(P[i][j])+tim[i], done[i]);
    return done[i];
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int t;
        scanf("%d %d", tim+i, &t);
        for(int j = 0; j < t; j++){
            int p; scanf("%d", &p);
            P[i].push_back(p-1);
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) ans = max(ans, rec(i));
    printf("%d\n", ans);
    return 0;
}
