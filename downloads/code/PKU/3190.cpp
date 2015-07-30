#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int N;
pii in[50010], out[50010];
int ans[50010];
int sz = 0;

int main(){
    scanf("%d", &N);
    priority_queue<int, vector<int>, greater<int> > que;
    for(int i = 0; i < N; i++){
        int a, b; scanf("%d%d", &a, &b);
        b++;
        in[i] = pii(a, i); out[i] = pii(b, i);
        que.push(i+1);
    }
    sort(in, in+N); sort(out, out+N);
    int i = 0, o = 0;
    while(i < N && o < N){
        if(in[i].first < out[o].first){
            ans[in[i].second] = que.top(); que.pop();
            sz = max(sz, ans[in[i].second]);
            i++;
        }else que.push(ans[out[o++].second]);
    }
    
    printf("%d\n", sz);
    for(int i = 0; i < N; i++)
        printf("%d\n", ans[i]);
    return 0;
}
