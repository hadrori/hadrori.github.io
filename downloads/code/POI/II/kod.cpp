#include <bits/stdc++.h>
using namespace std;

template<class T> class bit
{
        vector<T> dat;
        int N;
public:
        bit(int N) : N(N){
                dat.assign(N,0);
        }
        // sum [0,i)
        T sum(int i){
                T ret = 0;
                for(--i; i>=0; i=(i&(i+1))-1) ret += dat[i];
                return ret;
        }
        // sum [i,j)
        T sum(int i, int j){ return sum(j) - sum(i);}
        // add x to i
        void add(int i, T x){ for(; i < N; i|=i+1) dat[i] += x;}
};

int n, a[1<<15], b[1<<15];

int get_val(int i, bit<int> &bs)
{
        int lb = 0, ub = n, mid;
        while(ub-lb>1) {
                mid = (lb+ub)/2;
                if(n-mid-bs.sum(mid,n) > b[i]) lb = mid;
                else ub = mid;
        }
        return lb;
}

void solve()
{
        bit<int> bs(n+1);
        for (int i = n-1; i >= 0; i--) {
                if(b[i] > i) {
                        puts("NIE");
                        return;
                }
                int v = get_val(i,bs);
                a[i] = v+1;
                bs.add(v,1);
        }
        for (int i = 0; i < n; i++) printf("%d\n", a[i]);
}

void input()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", b+i);
}

int main()
{
        input();
        solve();
        return 0;
}
