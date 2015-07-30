#include <iostream>
#include <vector>

#define repi(i,a,b) for(int i = int(a); i < int(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back

using namespace std;

struct S{
    int l, r, s;
    S(int l, int r, int s):l(l),r(r),s(s){}
};

int n, x, m, atta;
vector<S> data;
int ans[8], ori[8];

void dfs(int cur){
    if(cur == n){
        rep(i,m){
            int l = data[i].l, r = data[i].r;
            int sum = 0;
            repi(j,l,r+1) sum += ori[j];
            if(sum != data[i].s) return;
        }
        int sum = 0;
        rep(i,n) sum += ori[i];
        if(sum > atta){
            rep(i,n) ans[i] = ori[i];
            atta = sum;
        }
        return;
    }
    rep(i,x+1){
        ori[cur] = i;
        dfs(cur+1);
    }
}

int main(){
    cin >> n >> x >> m;
    rep(_,m){
        int l, r, s;
        cin >> l >> r >> s;
        l--; r--;
        data.pb(S(l,r,s));
    }
    atta = -1;
    dfs(0);
    if(atta == -1) cout << atta << endl;
    else  rep(i,n) cout << ans[i] << (i==n-1? '\n': ' ');
}
