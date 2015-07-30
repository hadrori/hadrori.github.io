#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
const int inf = 1e9;
string op;
int idx;
string yaml[25010];

struct YAML{
    map<string,YAML*> child;
    int isString;
    string name, val;
    YAML(){}
};

void rec(YAML *root, int ind, int &ln){
    while(ln < idx){
        YAML *next = new YAML();
        string str = yaml[ln];
        int cnt = 0;
        while(str[cnt] == ' ') cnt++;
        if(cnt <= ind) return;
        string nm = "";
        int cur = cnt;
        while(str[cur] != ':') nm.pb(str[cur++]);
        cur++; ln++;
        next->name = nm;
        if(cur == (int)str.size()) rec(next, cnt, ln);
        else{
            next->isString = 1;
            next->val = str.substr(cur+1);
        }
        root->child[nm] = next;
    }
    return;
}

string solve(){
    YAML *root = new YAML();
    int ln = 0;
    rec(root, -1, ln);
    int cur = 0;
    YAML *next = root;
    while(cur < (int)op.size()){
        string obj = "";
        cur++;
        while(cur < (int)op.size() and op[cur] != '.') obj.pb(op[cur++]);
        if(next->child.count(obj) == 0) return "no such property";
        next = next->child[obj];
    }
    if(next->isString) return "string \""+next->val+"\"";
    return "object";
}

void input(){
    cin >> op;
    cin.ignore();
    idx = 0;
    while(getline(cin, yaml[idx])) idx++;
}
signed main(){
    input();
    cout << solve() << endl;
    return 0;
}


