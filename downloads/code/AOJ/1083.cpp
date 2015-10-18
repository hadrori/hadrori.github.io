#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)
 
template<class T> class bit {
public:
    vector<T> dat;
    int N;
     
    bit(){}
    bit(int N) : N(N) { dat.assign(N,0); }
    // sum [0,i)
    T sum(int i){
        T ret = 0;
        for(--i; i>=0; i=(i&(i+1))-1) ret += dat[i];
        return ret;
    }
    // sum [i,j)
    T sum(int i, int j) { return sum(j) - sum(i); }
    // add x to i
    void add(int i, T x) { for(; i < N; i|=i+1) dat[i] += x; }
};
 
 
bit<int> bs;
map<int,int> id;
int q, lim, l, r, vs[400010];
bool done[400010];
 
int get_pos(int p) {
    int lb = l, ub = r, mid;
    while(ub-lb > 1) {
        mid = (lb+ub)/2;
        if(bs.sum(mid) >= p) ub = mid;
        else lb = mid;
    }
    return lb;
}
 
void normalize() {
    if(bs.sum(r) > lim) {
        while(done[l]) l++;
        done[l] = 1;
        bs.add(l++,-1);
    }
}
 
void solve() {
    memset(done,0,sizeof(done));
    id.clear();
    l = r = 0;
    bs = bit<int>(q);
    while(q--) {
        int v, x;
        cin >> v >> x;
        if(v == 0) {
            id[x] = r;
            vs[r] = x;
            bs.add(r++,1);
        }
        else if(v == 1) {
            int p = get_pos(x);
            bs.add(p,-1);
            done[p] = 1;
        }
        else if(v == 2) cout << vs[get_pos(x)] << endl;
        else if(v == 3) {
            int p = id[x];
            bs.add(p, -1);
            done[p] = 1;
        }
        normalize();
    }
}
 
bool input() {
    cin >> q >> lim;
    return q or lim;
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    for(int t = 0; input(); t++) {
        solve();
        cout << "end" << endl;
    }
    return 0;
}