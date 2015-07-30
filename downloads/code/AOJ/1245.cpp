#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
const int inf = 1e9;
const int w = 8;
string s;
map<string,int> d;

bool ok(string &t){
    rep(i,4) for(int j = 0; j < 2*(w-2); j+=2){
        int a = atoi(t.substr(2*w*i+j,2).c_str());
        int b = atoi(t.substr(2*w*i+j+2,2).c_str());
        if(!a or !b or b-a != 1) return 0;
    }
    return 1;
}

int solve(){
    queue<string> bfs;
    bfs.push(s);
    while(!bfs.empty()){
        string t = bfs.front(); bfs.pop();
        int td = d[t];
        if(ok(t)) return td;
        int cand[4] = {}, pos[4] = {}, idx = 0;
        rep(i,4) for(int j = 2; j < 2*w; j+=2){
            if(t[2*w*i+j] == '0'){
                cand[idx] = atoi(t.substr(2*w*i+(j-2),2).c_str())+1;
                pos[idx++] = 2*w*i+j;
            }
        }
        rep(i,4) for(int j = 2; j < 2*w; j+=2){
            int a = atoi(t.substr(2*w*i+j,2).c_str());
            rep(k,4) if(cand[k] == a){
                string nx = t;
                nx[pos[k]] = t[2*w*i+j];
                nx[pos[k]+1] = t[2*w*i+j+1];
                nx[2*w*i+j] = nx[2*w*i+j+1] = '0';
                if(!d.count(nx)){
                    d[nx] = td+1;
                    bfs.push(nx);
                }
                break;
            }
        }
    }
    
    return -1;
}

bool input(){
    s = "";
    d.clear();
    string t;
    rep(i,4){
        s.pb(i+1+'0');
        s.pb('1');
        rep(j,7) {
            cin >> t;
            if(t[1] != '1') s += t;
            else s += "00";
        }
    }
    return 0;
}
signed main(){
    int T; cin >> T;
    while(T--){
        input();
        cout << solve() << endl;
    }
    return 0;
}


