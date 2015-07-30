#include <cstdio>
using namespace std;

const int mod = 1e9+9;
const int B = 550;

int n, m, a[300010], f[300010], sum[300010];
int qs[1000], nv[1000][2], i;

void gen(){
    f[0] = f[1] = 1;
    for(i=0;i<n;++i) f[i+2] = (f[i]+f[i+1])%mod, sum[i+1] = (sum[i]+f[i])%mod;
    for(i=0;i<n;++i) qs[i/B] = (qs[i/B]+a[i])%mod;
}

void update(int l, int r){
    int li = 0, ri = r-l;
    for(;l%B and l<r;++l,++li){
        qs[l/B] = (qs[l/B]+f[li])%mod;
        a[l] = (a[l]+f[li])%mod;
    }
    while(r%B and l < r){
        --r; --ri;
        qs[r/B] = (qs[r/B]+f[ri])%mod;
        a[r] = (a[r]+f[ri])%mod;
    }
    for(i=l/B;i<r/B;++i,li+=B){
        qs[i] = (qs[i]+(sum[li+B]-sum[li]+mod)%mod)%mod;
        nv[i][0] = (nv[i][0]+f[li])%mod;
        nv[i][1] = (nv[i][1]+f[li+1])%mod;
    }
}

int query(int l, int r){
    int ret = 0;
    if(l%B>B/2 or l/B==r/B){
        for(;l%B and l<r; ++l){
            ret = (ret+a[l])%mod;
            if(l%B>1) ret = (ret+1LL*f[l%B-1]*nv[l/B][1]+1LL*f[l%B-2]*nv[l/B][0])%mod;
            else ret = (ret+nv[l/B][l%B])%mod;
        }
    }
    else{
        while(l%B) {
            --l;
            ret = (ret-a[l]+mod)%mod;
            if(l%B>1) ret = (ret-(1LL*f[l%B-1]*nv[l/B][1]%mod+1LL*f[l%B-2]*nv[l/B][0]%mod)%mod+mod)%mod;
            else ret = (ret-nv[l/B][l%B]+mod)%mod;
        }
    }
    if(r%B<B/2){
        while(r%B and l < r){
            --r;
            ret = (ret+a[r])%mod;
            if(r%B>1) ret = (ret+1LL*f[r%B-1]*nv[r/B][1]+1LL*f[r%B-2]*nv[r/B][0])%mod;
            else ret = (ret+nv[r/B][r%B])%mod;
        }
    }
    else {
        for(;r%B and l<r; ++r){
            ret = (ret-a[r]+mod)%mod;
            if(r%B>1) ret = (ret-(1LL*f[r%B-1]*nv[r/B][1]%mod+1LL*f[r%B-2]*nv[r/B][0]%mod)%mod+mod)%mod;
            else ret = (ret-nv[r/B][r%B]+mod)%mod;
        }
    }
    for(i=l/B;i<r/B;++i)
        ret = (ret+qs[i])%mod;
    return ret;
}

void solve(){
    gen();
    int l, r, tp;
    while(m--){
        scanf("%d%d%d", &tp, &l, &r);
        l--;
        if(tp==1) update(l,r);
        else printf("%d\n", query(l,r));
    }
}

void input(){
    scanf("%d%d", &n, &m);
    for(i=0;i<n;++i) scanf("%d", a+i);
}

int main(){
    input();
    solve();
    return 0;
}
