#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
map<string,int> cnt;
set<int> done;
const int rot[][8] = {{1,2,3,0,5,6,7,4},
                      {6,7,1,0,2,3,5,4}};

void dfs(string &cl){
    int a = atoi(cl.c_str());
    if(done.count(a)) return;
    done.insert(a);
    rep(i,2){
        string tcl;
        rep(j,8) tcl.pb(cl[rot[i][j]]);
        dfs(tcl);
    }
    return;
}

int solve(){
    string cl;
    int idx = 0, ans = 0;
    for(auto it = begin(cnt); it != end(cnt); it++, idx++)
        rep(j,it->second) cl.pb(idx+'1');
    sort(all(cl));
    do{
        int a = atoi(cl.c_str());
        if(done.count(a)) continue;
        ans++;
        dfs(cl);
    } while(next_permutation(all(cl)));
    return ans;
}

bool input(){
    string s;
    if(!(cin >> s)) return 0;
    cnt.clear(); done.clear();
    cnt[s]++;
    rep(i,7) { cin >> s; cnt[s]++;}
    return 1;
}
signed main(){
    while(input()) cout << solve() << endl;
    return 0;
}


