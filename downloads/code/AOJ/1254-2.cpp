#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
typedef pair<int,int> pt;
vector<pt> G[128];
map<string, int> id;
int ctr[128], to[16], col[16];
int N, V;

pt operator-(const pt &a, const pt &b){ return pt(a.first-b.first, a.second-b.second);}
inline int cross(pt a, pt b){ return a.first*b.second-a.second*b.first;}
inline bool isPar(pt a1, pt a2, pt b1, pt b2){ return !cross(a1-a2, b1-b2);}
inline int sq(int a){ return a*a;}
inline int mpow(int a, int k){ return k==0? 1: k%2? a*mpow(a,k-1): mpow(a*a,k/2);}
inline double pabs(pt a){ return sqrt(sq(a.first)+sq(a.second));}
inline bool isOn(pt a1, pt a2, pt p){ return a1!=p and a2!=p and pabs(a1-p)+pabs(a2-p)<pabs(a1-a2)+1e-9;}

int ans;
void paint(int v, int k){
    if(k >= ans) return;
    if(v == V){
        ans = k;
        return;
    }
    bool used[16] = {};
    rep(i,V) if(col[i]>=0 and (to[v]&(1<<i))) used[col[i]] = 1;
    rep(i,k+1) if(!used[i]) {
        col[v] = i;
        paint(v+1,max(i+1,k));
    }
    col[v] = -1;
}

int solve(){
    memset(to,0,sizeof(to));
    memset(col,-1,sizeof(col));
    rep(i,N) rep(j,N) if(!(to[ctr[i]]&(1<<ctr[j]))){
        int n = G[i].size(), m = G[j].size();
        rep(u,n) rep(v,m){
            pt &a1 = G[i][u], &a2 = G[i][(u+1)%n];
            pt &b1 = G[j][v], &b2 = G[j][(v+1)%m];
            if(!isPar(a1,a2,b1,b2)) continue;
            if((a1==b1 and a2==b2) or (a1==b2 and a2==b1) or
               isOn(a1,a2,b1) or isOn(a1,a2,b2) or isOn(b1,b2,a1) or isOn(b1,b2,a2)){
                to[ctr[i]] |= 1<<ctr[j];
                to[ctr[j]] |= 1<<ctr[i];
                goto next;
            }
        }
    next:;
    }
    ans = V;
    paint(0,1);
    return ans;
}

bool input(){
    cin >> N;
    id.clear();
    rep(i,N){
        G[i].clear();
        string s; cin >> s;
        if(!id.count(s)) id[s] = id.size()-1;
        ctr[i] = id[s];
        int x, y;
        while(cin >> x, x >= 0){
            cin >> y;
            G[i].pb(pt(x,y));
        }
    }
    V = id.size();
    return N;
}
signed main(){
    while(input()) cout << solve() << endl;
    return 0;
}
