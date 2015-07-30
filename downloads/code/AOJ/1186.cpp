#include <bits/stdc++.h>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define all(u) (u).begin(),(u).end()
#define pb push_back
using namespace std;

struct S{
    int w, h, diag;
    S(int w, int h):w(w),h(h){
        diag = h*h + w*w;
    }
    bool operator < (const S &s) const{
        if(diag < s.diag) return 1;
        if(diag > s.diag) return 0;
        return h < s.h; 
    }
};

int main(){
    vector<S> rect;
    repi(i,1,200)repi(j,i+1,200){
        rect.pb(S(j, i));
    }
    sort(all(rect));
    int h, w;
    while(cin >> h >> w, h || w){
        S s = S(w, h);
        S t = *(++lower_bound(all(rect), s));
        cout << t.h << ' ' << t.w << endl;
    }
    return 0;
}
