#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<int> edge[10010];
vector<int> ans;

int dfs(int p, int from){
    int ret = 1, tmp;
    bool ok = 1;
    for(int i = 0; i < edge[p].size(); i++){
        if(edge[p][i] == from) continue;
        tmp = dfs(edge[p][i], p);
        if(tmp > N / 2) ok = 0;
        ret += tmp;
    }
    tmp = N-ret;
    if(tmp > N / 2) ok = 0;
    if(ok) ans.push_back(p+1);
    return ret;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N-1; i++){
        int a, b; scanf("%d%d", &a, &b);
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(0, 0);
    sort(ans.begin(), ans.end());
    if(ans.size() == 0) printf("NONE\n");
    else {
        for(int i = 0; i < ans.size(); i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
