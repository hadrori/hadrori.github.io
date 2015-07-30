#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, ans;
int op[16];
vector<vector<int> > seq;

void dfs(int cur, int sum, int res){
    if(cur == N){
        if(sum + res == 0){
            ans++;
            if(seq.size() < 20){
                seq.push_back(vector<int>());
                for(int i = 0; i < N-1; i++)
                    seq.back().push_back(op[i]);
            }
        }
        return;
    }
    if(abs(sum) > 1e7 || abs(res) > 1e7) return;
    for(int i = 0; i < 3; i++){
        op[cur-1] = i;
        int tmp = res;
        if(i < 2){
            sum += res;
            res = cur+1;
            if(i==1) res *= -1;
        }
        else{
            if(cur+1 < 10) res *= 10;
            else res *= 100;
            res = res < 0 ? res - cur - 1: res + cur + 1;
        }
        dfs(cur+1, sum, res);
        if(i < 2) sum -= tmp;
        res = tmp;
    }
}

int main(){
    scanf("%d", &N);
    dfs(1,0,1);
    for(int i = 0; i < seq.size(); i++){
        printf("1");
        for(int j = 0; j < N-1; j++){
            if(seq[i][j] == 0) printf(" +");
            else if(seq[i][j] == 1) printf(" -");
            else printf(" .");
            printf(" %d", j+2);
        }
        puts("");
    }
    printf("%d\n", ans);
    return 0;
}
