#include <bits/stdc++.h>
using namespace std;
 
// T have +- and 0
template<class T> class bit
{
public:
        vector<T> dat;
        int N;
        
        bit(){}
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

struct ask { int p, q, r;};

const int B = 1000;
int n, m, k, c;
int s[100010], t[100010];
bit<int> bs[100000/B+10];
vector<int> ps;
vector<ask> qs;

void prepare()
{
        sort(begin(ps),end(ps));
        ps.erase(unique(begin(ps),end(ps)),end(ps));
        c = ps.size();
        for (int i = 0; i < n; i++) {
                s[i] = lower_bound(begin(ps),end(ps), s[i])-begin(ps);
                t[i] = lower_bound(begin(ps),end(ps), t[i])-begin(ps);
        }
        
        bit<int> b(c);
        bs[0] = b;
        for (int i = 0; i <= n/B; i++) {
                for (int j = 0; j < B; j++) {
                        if(i*B+j >= n) break;
                        b.add(s[i*B+j],1);
                        b.add(t[i*B+j],-1);
                }
                bs[i+1] = b;
        }
}

int query(int p_, int l, int r)
{
        int ret = 0, p = lower_bound(begin(ps),end(ps), p_)-begin(ps);

        while(l%B and l<r) { ret += (s[l]<=p and p<t[l])? 1: 0; l++;}
        while(r%B and l<r) { r--; ret += (s[r]<=p and p<t[r])? 1: 0;}

        return ret+(l!=r? bs[r/B].sum(p+1)-bs[l/B].sum(p+1):0);
}
 
void solve()
{
        prepare();
        
        for(auto &e: qs) cout << query(e.p, e.q, e.r) << endl;
}
 
void input()
{
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++) {
                int a, b;
                cin >> a >> b;
                s[i] = a-1;
                t[i] = b;
        }
        for (int i = 0; i < m; i++) {
                int p, q, r;
                cin >> p >> q >> r; --p; --q;
                ps.push_back(p);
                qs.push_back((ask){p,q,r});
        }

}
 
int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
