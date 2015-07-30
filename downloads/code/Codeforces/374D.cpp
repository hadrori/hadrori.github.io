#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
const int inf = 1e9;
const int M = 1000010;

const int MAX = M;
// BIT is 0 indexed
struct BIT{
    int bit[MAX+1], N;
    BIT(){}
    BIT(int N):N(N){
        memset(bit, 0, sizeof(bit));
    }
    // sum [0,i]
    int sum(int i){
        i++;
        int ret = 0;
        while(i){
            ret += bit[i];
            i -= i&-i;
        }
        return ret;
    }
    // sum [i,j)
    int sum(int i, int j){
        return sum(j-1) - sum(i-1);
    }
    
    void add(int i, int x){
        i++;
        while(i <= N){
            bit[i] += x;
            i += i&-i;
        }
    }
    int find(int i){
        int lb = -1, ub = N, mid;
        while(ub - lb > 1){
            mid = (lb+ub)/2;
            if(sum(mid) >= i) ub = mid;
            else lb = mid;
        }
        return ub;
    }
};


int n, m, a[M], seq[M], k[M];
int len, ns, ms;
BIT b;

void solve(){
    if(!len){
        puts("Poor stack!");
        return;
    }
    b = BIT(ns);
    rep(i,ns) b.add(i,1);
    rep(i,ms){
        for(int j = k[i]-1; j >= 0; --j){
            int pos = b.find(a[j]);
            b.add(pos,-1);
        }
    }
    rep(i,ns) if(b.sum(i,i+1)) printf("%d", seq[i]);
    puts("");
}

void input(){
    scanf("%d%d", &n, &m);
    rep(i,m) scanf("%d", a+i);
    rep(i,n){
        scanf("%d", seq+ns);
        if(seq[ns] < 0){
            if(a[0] > len) continue;
            k[ms] = lower_bound(a,a+m,len+1)-a;
            len -= k[ms++];
        }
        else ++len, ++ns;
    }
}

int main(){
    input();
    solve();
    return 0;
}
