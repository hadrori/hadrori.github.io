#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i,a) for(int i = 0;i < (a); i++)
#define all(u) (u).begin(),(u).end()
#define pb push_back
using namespace std;
typedef vector<int> vi;

int L, N, M;
vi dist;

bool can(int len){
    int prev = 0;
    int cnt = 0;
    rep(i,N){
        if(dist[i] - prev < len) cnt++;
        else prev = dist[i];
    }
    return cnt <= M;
}

int main(){
    cin >> L >> N >> M;
    rep(i,N){
        int t; cin >> t;
        dist.pb(t);
    }
    sort(all(dist));
    int lb = 0, ub = L;
    while(lb < ub){
        int mid = (lb + ub + 1) / 2;
        if(can(mid)) lb = mid;
        else ub = mid - 1;
    }
    cout << lb << endl;
    return 0;
}
