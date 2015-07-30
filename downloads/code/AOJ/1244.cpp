#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
const int inf = 1e9;
string seq;
map<string, int> w;
int cur;

int num(){
    int ret = 0;
    while(cur < seq.size() and isdigit(seq[cur]))
        ret = 10*ret+seq[cur++]-'0';
    return ret;
}

int atm(){
    string a = seq.substr(cur,1);
    cur++;
    while(cur < seq.size() and islower(seq[cur]))
        a.pb(seq[cur++]);
    auto it = w.find(a);
    if(it == end(w)) return -1;
    return it->second;
}

int mol(){
    if(cur == seq.size()) return 0;
    int ret = 0;
    if(seq[cur] == ')') return 0;
    if(seq[cur] == '('){
        ++cur;
        ret = mol();
        ++cur;
        if(ret < 0) return ret;
        ret *= num();
        int d = mol();
        if(d < 0) return d;
        return ret+d;
    }
    ret = atm();
    if(ret < 0) return ret;
    ret *= max(1,num());
    int d = mol();
    if(d < 0) return d;
    return ret+d;
}

void solve(){
    while(1){
        cin >> seq;
        if(seq == "0") break;
        cur = 0;
        int ans = mol();
        if(ans < 0) puts("UNKNOWN");
        else cout << ans << endl;
    }
}

void input(){
    string s;
    while(1){
        cin >> s;
        if(s == "END_OF_FIRST_PART") break;
        int d; cin >> d;
        w[s] = d;
    }
}

signed main(){
    input();
    solve();
    return 0;
}


