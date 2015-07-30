#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
int N;
int used[10010], re[10010], num[10010];
string mark[10010];
map<string, int> id;

void solve(){
    memset(used,0,sizeof(used));
    memset(re,0,sizeof(re));
    memset(num, -1, sizeof(num));
    id.clear();
    rep(i,N) if(mark[i][mark[i].size()-1] == 'v'){
        mark[i] = mark[i].substr(0,mark[i].size()-1);
        re[i] = 1;
    }
    rep(i,N) if(mark[i].size() > 1){
        rep(j,mark[i].size()) if(isdigit(mark[i][j])){
            num[i] = atoi(mark[i].substr(j).c_str());
            mark[i] = mark[i].substr(0,j);
            if(!id.count(mark[i])) id[mark[i]] = id.size()-1;
            break;
        }
    }
    vector<int> jmp[10010];
    stack<int> stk;
    rep(i,N){
        if(num[i] > 1) {
            jmp[id[mark[i]]].pb(i);
            continue;
        }
        if(re[i]) continue;
        stk.push(i);
        while(!stk.empty()){
            int cur = stk.top(); stk.pop();
            if(used[cur]) continue;
            cout << cur+1 << endl;
            used[cur] = 1;
            if(num[cur] == 1){
                int k = id[mark[cur]];
                rep(j,jmp[k].size())
                    stk.push(jmp[k][j]);
                jmp[k].clear();
            }
            if(cur > 0 and re[cur-1]) stk.push(cur-1);
        }
    }
}

bool input(){
    cin >> N;
    rep(i,N) cin >> mark[i];
    return N;
}

int main(){
    while(input()) solve();
    return 0;
}


