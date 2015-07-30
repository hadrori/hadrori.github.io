#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

typedef pair<int,int> pii;

int N, T;
pii sect[25010];

int main(){
    scanf("%d%d", &N, &T);
    for(int i = 0; i < N; i++){
        int a, b; scanf("%d%d", &a, &b);
        sect[i] = pii(a-1,b);
    }
    sort(sect, sect+N);
    int ans = 0;
    int r = 0, pos = 0;
    while(r < T){
        int mr = 0;
        while(pos < N && sect[pos].first <= r)
            mr = max(mr, sect[pos++].second);
        ans++;
        if(pos == N){
            if(mr < T) ans = -1;
            break;
        }
        if(mr == 0){
            ans = -1;
            break;
        }
        r = mr;
    }
    printf("%d\n", ans);
    return 0;
}
