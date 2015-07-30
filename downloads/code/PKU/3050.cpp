#include <cstdio>
#include <set>

using namespace std;

int table[5][5];
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

set<int> nums;

inline bool in(int i, int j){ return i >= 0 && i < 5 && j >= 0 && j < 5;}

void dfs(int i, int j, int cnt, int seq){
    if(cnt == 5){
        nums.insert(seq);
        return;
    }
    for(int k = 0; k < 5; k++){
        int ni = i + di[k], nj = j + dj[k];
        if(in(ni, nj)) dfs(ni, nj, cnt+1, seq*10+table[ni][nj]);
    }
}

int main(){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            scanf("%d", &table[i][j]);

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            dfs(i, j, 0, table[i][j]);

    printf("%d\n", nums.size());
}
