#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
typedef pair<double,int> pdi;
typedef pair<int,int> pii;
struct node{
    int l, r; double d;
    node(int l, int r, double d):
        l(l),r(r),d(d){}
    bool operator<(const node &n)const{ return d > n.d;}
};
int N, X[128], Y[128];
vector<pdi> G;
set<pii> done;

inline bool on(int i, int j){ return (Y[i] < Y[j] and Y[j] < Y[i+1]) or (Y[i] > Y[j] and Y[j] > Y[i+1]);}
inline bool in(int l, int r){ return l >= 0 and l < N and r >= 0 and r < N;}
inline double get_x(int i, int h){ return X[i+(Y[i]>Y[i+1])]+1.*h*(X[i+1]-X[i])/abs(Y[i]-Y[i+1])*(Y[i]>Y[i+1]?-1:1);}
inline double sq(double a){ return a*a;}
inline double dd(int i, int j){ return sqrt(sq(G[i].first-G[j].first)+sq(G[i].second-G[j].second));}

double solve(){
    G.clear(); done.clear();
    rep(i,N){
        G.pb(pdi(X[i],Y[i]));
        if(i == N-1) break;
        bool used[1024] = {};
        rep(j,N-1)if(!used[Y[j]] and on(i,j)){
            G.pb(pdi(get_x(i,Y[j]-min(Y[i],Y[i+1])), Y[j]));
            used[Y[j]] = 1;
        }
    }
    N = G.size(); sort(all(G));
    priority_queue<node> q;
    q.push(node(0,N-1,0));
    while(!q.empty()){
        node v = q.top(); q.pop();
        if(v.l == v.r) return v.d;
        if(done.count(pii(v.l,v.r))) continue;
        done.insert(pii(v.l,v.r));
        repi(dl,-1,2)repi(dr,-1,2)
            if(in(v.l+dl,v.r+dr) and G[v.l+dl].second == G[v.r+dr].second)
                q.push(node(v.l+dl,v.r+dr,v.d+dd(v.l,v.l+dl)+dd(v.r,v.r+dr)));
    }
    return 0;
}

bool input(){
    cin >> N;
    rep(i,N) cin >> X[i] >> Y[i];
    return N;
}
int main(){
    while(input()) printf("%.8f\n", solve());
    return 0;
}
