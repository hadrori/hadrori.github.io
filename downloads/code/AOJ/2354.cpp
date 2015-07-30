#include <bits/stdc++.h>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define rall(u) (u).rbegin(),(u).rend()
#define pb push_back
#define EPS 1e-10

using namespace std;
struct S{
    int w, v;
    S(int w, int v):w(w),v(v){}
    bool operator<(const S &s) const{
        return s.w * v < w * s.v;
    }
};

int main(){
    double N, W, ans = 0;
    cin >> N >> W;
    vector<S> p;
    rep(i,N){
        int w, v;
        cin >> w >> v;
        if(w <= 0 && v >= 0){
            ans += v;
            W -= w;
        }
        else if(w >= 0 && v <= 0) continue;
        else if(w < 0 && v < 0){
            ans += v; W -= w;
            p.pb(S(-w,-v));
        }
        else p.pb(S(w,v));
    }
    sort(rall(p));

    rep(i,p.size()){
        int tw = p[i].w, tv = p[i].v;
        double x = min(1.0, W/tw);
        ans += x * tv;
        W -= x * tw;
        if(W < EPS) break;
    }
    printf("%.8f\n",ans);
    return 0;
}
