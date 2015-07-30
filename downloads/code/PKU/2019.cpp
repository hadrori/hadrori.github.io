#include <cstdio>
#include <map>

using namespace std;

int N, B, K;
int table[256][256];
int ans[256][256];

int main(){
    scanf("%d%d%d", &N, &B, &K);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &table[i][j]);

    map<int, int> cnt;
    for(int i = 0; i < B; i++)
        for(int j = 0; j < B; j++)
            cnt[table[i][j]]++;

    for(int i = 0; i < N-B+1; i++){
        if(i%2==0){
            for(int j = 0; j < N-B+1; j++){
                map<int,int>::iterator itr1 = cnt.end();
                map<int,int>::iterator itr2 = cnt.begin();
                ans[i][j] = ((--itr1)->first) - (itr2->first);
                if(j == N-B) continue;
                for(int ti = i; ti < i + B; ti++){
                    cnt[table[ti][j+B]]++;
                    cnt[table[ti][j]]--;
                    if(cnt[table[ti][j]] == 0)
                        cnt.erase(table[ti][j]);
                }
            }
            if(i == N - B) continue;
            for(int tj = N-B; tj < N; tj++){
                cnt[table[i+B][tj]]++;
                cnt[table[i][tj]]--;
                if(cnt[table[i][tj]] == 0)
                    cnt.erase(table[i][tj]);
            }
        }
        else{
            for(int j = N-B; j >= 0; j--){
                map<int,int>::iterator itr1 = cnt.end();
                map<int,int>::iterator itr2 = cnt.begin();
                ans[i][j] = ((--itr1)->first) - (itr2->first);
                if(j == 0) continue;
                for(int ti = i; ti < i + B; ti++){
                    cnt[table[ti][j-1]]++;
                    cnt[table[ti][j+B-1]]--;
                    if(cnt[table[ti][j+B-1]] == 0)
                        cnt.erase(table[ti][j+B-1]);
                }
            }
            if(i == N - B) continue;
            for(int tj = 0; tj < B; tj++){
                cnt[table[i+B][tj]]++;
                cnt[table[i][tj]]--;
                if(cnt[table[i][tj]] == 0)
                    cnt.erase(table[i][tj]);
            }
        }
        
    }
    
    while(K--){
        int i, j; scanf("%d%d", &i, &j);
        i--; j--;
        printf("%d\n", ans[i][j]);
    }
    /*
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++)
            printf("%d ", ans[i][j]);
        puts("");
    }
    */
    return 0;
}
