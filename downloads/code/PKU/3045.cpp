#include <algorithm>
#include <iostream>
#include <vector>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define all(u) (u).begin(),(u).end()
#define pb push_back
#define INF 1e9
using namespace std;

int N;
struct S{
    int w, s;
    S(int w, int s):w(w),s(s){}
    bool operator < (const S &t) const{ return w + s < t.w + t.s;}
};

int main(){
    cin >> N;
    vector<S> cows;
    rep(i,N){
        int w, s; scanf("%d %d", &w, &s);
        cows.pb(S(w,s));
    }
    sort(rall(cows));
    int sum = 0, ans = -INF;
    repd(i,N-1,0){
        ans = max(ans, sum - cows[i].s);
        sum += cows[i].w;
    }
    cout << ans << endl;
    return 0;
}
