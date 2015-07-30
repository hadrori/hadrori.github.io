#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
struct swimmer{
    int t, res, v;
    bool operator<(const swimmer &s)const{ return v < s.v;}
};
int N, a, b;

int solve(){
    queue<swimmer> que[2];
    rep(i,N){
        cin >> a >> b;
        que[0].push((swimmer){0,b,a});
    }
    int ans = 0;
    while(!que[0].empty() or !que[1].empty()){
        int f = que[0].empty() or (!que[1].empty() and que[1].front().t < que[0].front().t);
        ans = que[f].front().t;
        vector<swimmer> s;
        while(!que[f].empty() and que[f].front().t <= ans){
            s.pb(que[f].front()); que[f].pop();
        }
        sort(all(s));
        rep(i,s.size()) if(s[i].res)
            que[f^1].push((swimmer){ans+s[i].v, s[i].res-f, s[i].v});
    }
    return ans;
}

signed main(){
    while(cin >> N, N)
        cout << solve() << endl;
    return 0;
}


