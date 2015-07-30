#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
typedef pair<ull,int> pli;
ull A;
const int M = 4;
map<ull,int> d[2];
int a[16], N;

void bfs(int f){
    queue<pli> que;
    d[f][A] = 0;
    que.push(pli(A,0));
    while(!que.empty()){
        ull u = que.front().first;
        int td = que.front().second;
        que.pop();
        if(td == min(4,N/2)) continue;
        for(int i = N-1; i >= 0; i--) {
            a[i] = u&((1<<M)-1);
            u >>= M;
        }
        rep(l,N) repi(r,l+1,N){
            reverse(a+l, a+r+1);
            ull v = 0;
            rep(i,N) v = (v<<M)+a[i];
            if(!d[f].count(v)){
                que.push(pli(v,td+1));
                d[f][v] = td+1;
            }
            reverse(a+l, a+r+1);
        }
    }
}

int solve(){
    bfs(0);
    A = 0;
    rep(i,N) A = (A<<M)+i;
    bfs(1);
    int ans = N-1;
    for(auto it = begin(d[0]); it != end(d[0]); it++){
        auto jt = d[1].find(it->first);
        if(jt != end(d[1])) ans = min(ans, it->second+jt->second);
    }
    return ans;
}
void input(){
    cin >> N;
    A = 0;
    rep(i,N) {
        int c;
        cin >> c;
        A = (A<<M)+(c-1);
    }
} 
signed main(){
    input();
    cout << solve() << endl;
    return 0;
}


