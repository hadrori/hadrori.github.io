#include <bits/stdc++.h>
using namespace std;

// T have +- and 0
template<class T, int M> class bit
{
public:
        T dat[M+1];
        int N;

        bit(){}
        bit(int N) : N(N){
                fill(dat,dat+N,0);
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


int n, b[1000010], f[1000010];

long long solve()
{
        map<int,int> cnt;
        bit<int,1000000> bt(n+1);
        long long ans = 0;

        for (int i = 0; i < n; i++) 
                f[i] = ++cnt[b[i]];

        cnt.clear();
        for (int i = n-1; i >= 0 ; i--) {
                ans += bt.sum(f[i]);
                bt.add(++cnt[b[i]],1);
        }

        return ans;
}

void input()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                scanf("%d", b+i);
        }
}

int main()
{
        input();
        cout << solve() << endl;
        return 0;
}
