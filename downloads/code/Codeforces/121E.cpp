#include <string.h>
#include <math.h>
#include <stdio.h>

int n, m, seq[100010], i, j;
bool islucky[10010];
int lucky[] = {4,7,44,47,74,77,444,447,474,477,744,747,774,777,4444,4447,4474,4477,4744,4747,4774,4777,7444,7447,7474,7477,7744,7747,7774,7777};
struct sqdiv{
    int N, M;
    int cnt[500][10010], sum[500];
    sqdiv(int n){
        N = n;
        M = 500;
        memset(sum, 0, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));
    }
    // add d for [l,r)
    void add(int l, int r, int d){
        while(l%M and l < r) {
            cnt[l/M][seq[l]]--;
            seq[l] += d;
            cnt[l/M][seq[l]]++;
            ++l;
        }
        while(r%M and l < r) {
            --r;
            cnt[r/M][seq[r]]--;
            seq[r] += d;
            cnt[r/M][seq[r]]++;
        }
        for(i = l/M; i < r/M; i++) sum[i] += d;
    }
    // count lucky [l,r)
    int count(int l, int r){
        int ret = 0;
        while(l%M and l < r) ret += islucky[seq[l]+sum[l++/M]];
        while(r%M and l < r) ret += islucky[seq[--r]+sum[r/M]];
        for(i = l/M; i < r/M; i++)
            for(j = 0; j < 30; j++)
                if(lucky[j] >= sum[i])
                    ret += cnt[i][lucky[j]-sum[i]];
        return ret;
    }
};

int main(void){
    for(i = 0; i < 30; i++)
        islucky[lucky[i]] = 1;
    scanf("%d%d", &n, &m);
    sqdiv sd(n);
    for(i = 0; i < n; i++){
        scanf("%d", seq+i);
        sd.cnt[i/sd.M][seq[i]]++;
    }
    while(m--){
        char s[8]; scanf("%s", s);
        int l, r, d; scanf("%d%d", &l, &r); l--;
        if(!strcmp(s,"count")) printf("%d\n", sd.count(l,r));
        else{
            scanf("%d", &d);
            sd.add(l,r,d);
        }
    }
    return 0;
}
