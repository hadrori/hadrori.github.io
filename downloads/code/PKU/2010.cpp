#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

typedef pair<int,int> pii;
int N, C, F, M;
pii calves[100010];
int sumf[100010], sumb[100010];

int main(){
    scanf("%d%d%d", &N, &C, &F);
    M = N/2;
    for(int i = 0; i < C; i++){
        int a, b; scanf("%d%d", &a, &b);
        calves[i] = pii(a,b);
    }
    sort(calves, calves+C);
    {
        priority_queue<int> que;
        int sum = 0;
        for(int i = 0; i < M; i++){
            que.push(calves[i].second);
            sum += calves[i].second;
            sumf[i] = sum;
        }
        for(int i = M; i < C-M; i++){
            sum += calves[i].second;
            que.push(calves[i].second);
            sum -= que.top(); que.pop();
            sumf[i] = sum;
        }
        while(!que.empty()) que.pop();
        sum = 0;
        for(int i = 0; i < M; i++){
            que.push(calves[C-i-1].second);
            sum += calves[C-i-1].second;
            sumb[C-i-1] = sum;
        }
        for(int i = M; i < C-M; i++){
            sum += calves[C-i-1].second;
            que.push(calves[C-i-1].second);
            sum -= que.top(); que.pop();
            sumb[C-i-1] = sum;
        }
    }
    int ans = -1;
    /*
    for(int i = 0; i < C; i++)
        printf("%d ", calves[i].first);
    puts("");
    for(int i = 0; i < C; i++)
        printf("%d ", calves[i].second);
    puts("");
    for(int i = 0; i < C; i++)
        printf("%d ", sumf[i]);
    puts("");
    for(int i = 0; i < C; i++)
        printf("%d ", sumb[i]);
    puts("");

    for(int i = C-M-1; i >= M; i--){
        printf("%d\n", i);
        if(calves[i].second + sumf[i-1] + sumb[i+1] <= F){
            ans = calves[i].first;
            printf("  %d %d\n", ans, calves[i].second+sumf[i-1]+sumb[i+1]);
        }
    }
    */
    for(int i = C-M-1; i >= M; i--)
        if(calves[i].second + sumf[i-1] + sumb[i+1] <= F){
            ans = calves[i].first;
            break;
        }
    printf("%d\n", ans);
    return 0;
}
