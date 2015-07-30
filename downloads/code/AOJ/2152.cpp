#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
#define fst first
#define snd second
#define INF 1e9

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

int n;
map<int,int> id;
bool deleted[10010];
vector<pii> data;
const int M = 10005;

void init(){
    id.clear();
    memset(deleted, 0, sizeof(deleted));
    id[M] = 0;
    deleted[0] = true;
    data.clear();
    data.pb(pii(M,INF+10));
}

void write(int cnt){
    int l, s; cin >> l >> s;
    id[l] = cnt;
    rep(i,data.size()){
        if(deleted[id[data[i].fst]]){
            if(data[i].snd <= s){
                data[i].fst = l;
                s -= data[i].snd;
            }
            else{
                data.insert(data.begin()+i+1,pii(M,data[i].snd - s));
                data[i].fst = l;
                data[i].snd = s;
                s = 0;
            }
            if(!s) return;
        }
    }
    return;
}

int read(){
    int p; cin >> p;
    p++;
    rep(i,data.size()){
        if(p > data[i].snd) p -= data[i].snd;
        else if(deleted[id[data[i].fst]]) return -1;
        else return data[i].fst;
    }
    return -1;
}

void del(){
    int l; cin >> l;
    l = id[l];
    deleted[l] = true;
}

int main(){
    while(cin >> n, n){
        int cnt = 0;
        init();
        while(n--){
            char com; cin >> com;
            if(com == 'W') write(++cnt);
            if(com == 'R') cout << read() << endl;
            if(com == 'D') del();
        }
        cout << endl;
    }
    return 0;
}
