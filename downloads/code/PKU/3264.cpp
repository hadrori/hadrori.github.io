#include <cstdio>
#include <algorithm>

#include <iostream>

using namespace std;

const int inf = 1e9;
int N, Q, M;

struct ST{
    int sh[1<<17], he[1<<17];
    ST(){
        for(int i = 0; i < 2*M-1; i++){
            sh[i] = inf; he[i] = 0;
        }
    }
    void update(int val, int k){
        k += M-1;
        sh[k] = he[k] = val;
        while(k > 0){
            k = (k-1) / 2;
            sh[k] = min(sh[2*k+1], sh[2*k+2]);
            he[k] = max(he[2*k+1], he[2*k+2]);
        }
    }
    int get_min(int a, int b){ return get_min(a, b, 0, 0, M);}
    int get_min(int a, int b, int k, int l, int r){
        if(a >= r or b <= l) return inf;
        if(a <= l and r <= b) return sh[k];
        int m = (l + r) / 2;
        return min(get_min(a,b,2*k+1,l,m), get_min(a,b,2*k+2,m,r));
    }
    int get_max(int a, int b){ return get_max(a, b, 0, 0, M);}
    int get_max(int a, int b, int k, int l, int r){
        if(a >= r or b <= l) return 0;
        if(a <= l and r <= b) return he[k];
        int m = (l + r) / 2;
        return max(get_max(a,b,2*k+1,l,m), get_max(a,b,2*k+2,m,r));
    }
};

int main(){
    scanf("%d%d", &N, &Q);
    M = 1;
    while(M < N) M <<= 1;
    ST st = ST();
    for(int i = 0; i < N; i++){
        int h; scanf("%d", &h);
        st.update(h, i);
    }
    while(Q--){
        int a, b; scanf("%d%d", &a, &b);
        a--;
        //        cerr << a << " " << b << " " << st.get_max(a,b) << " " << st.get_min(a,b) << endl;
        printf("%d\n", st.get_max(a,b)-st.get_min(a,b));
    }
    return 0;
}
