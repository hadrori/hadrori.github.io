#include <cstdio>

using namespace std;

int N, T, R[10010], MR, id;

int main(){
    scanf("%d%d", &N, &T);
    for(int i = 0; i < N; i++){
        scanf("%d", R+i);
        if(R[i] > MR){
            MR = R[i];
            id = i;
        }
    }
    if(N == 1) while(T --> 0) puts("1");
    else while(T --> 0){
            printf("%d\n", id+1);
            int tid = id, tMR = 0, res = R[id] % (N-1);
            R[id] = 0;
            for(int i = 0; i < N; i++)
                if(i != id){
                    R[i] += MR / (N-1);
                    if(res) R[i]++, res--;
                    if(tMR < R[i]){
                        tMR = R[i];
                        tid = i;
                    }
                }
            id = tid;
            MR = tMR;
    }
    return 0;
}
