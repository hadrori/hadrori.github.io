#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
struct dice{
    int val[6];
    void roti(){int t=val[5];val[5]=val[1];val[1]=val[4];val[4]=val[0];val[0]=t;}
    void rotj(){int t=val[3];val[3]=val[1];val[1]=val[2];val[2]=val[0];val[0]=t;}
    void rotk(){int t=val[3];val[3]=val[4];val[4]=val[2];val[2]=val[5];val[5]=t;}
};
int F[3][3], T[3][3];
dice cube[3][3][3];
vector<int> ans;

void rec(int cur){
    if(cur == 27){
        int sum = 0;
        rep(i,3)rep(k,3) sum += cube[i][2][k].val[4];
        ans.pb(sum);
        return;
    }
    int k = cur/9, i = cur/3%3, j = cur%3;
    dice d = (dice){2,5,6,1,3,4};
    rep(r,24){
        d.rotk();
        if(!(r%4)){
            if(r < 16) d.rotj();
            else if(r == 16) d.roti();
            else rep(_,2) d.roti();
        }
        if(k==0 and T[i][j] and T[i][j] != d.val[0]) continue;
        if(i==2 and F[k][j] and F[k][j] != d.val[2]) continue;
        if(i and cube[i-1][j][k].val[2]+d.val[3]!=7) continue;
        if(j and cube[i][j-1][k].val[4]+d.val[5]!=7) continue;
        if(k and cube[i][j][k-1].val[1]+d.val[0]!=7) continue;
        cube[i][j][k] = d;
        rec(cur+1);
    }
}

void solve(){
    ans.clear();
    memset(cube, 0, sizeof(cube));
    rec(0);
    if(ans.size()==0) {
        cout << 0 << endl;
        return;
    }
    sort(all(ans));
    ans.erase(unique(all(ans)),ans.end());
    rep(i,ans.size()) cout << ans[i] << (i==int(ans.size()-1)? '\n': ' ');
}

void input(){
    rep(i,3)rep(j,3) cin >> T[i][j];
    rep(i,3)rep(j,3) cin >> F[i][j];
}
signed main(){
    int __;
    cin >> __;
    while(__--){
        input();
        solve();
    }
    return 0;
}


