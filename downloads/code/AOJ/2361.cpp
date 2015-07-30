#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
typedef vector<int> vi;
typedef pair<int,int> pii;

int vtoi(vi &v){
    int ret = 0;
    rep(i,v.size()){
        ret *= 10;
        ret += v[i];
    }
    return ret;
}

void itov(int n, vi &v){
    int t = v.size();
    rep(i,t){
        v[t-i-1] = n%10;
        n/=10;
    }
}

int main(){
    int n;
    cin >> n;
    vector<vi> cost(n,vi(n));
    rep(i,n)rep(j,n) cin >> cost[i][j];
    vi v(n);
    rep(i,n) v[i] = i;
    int num = vtoi(v);
    priority_queue<pii> que;
    map<int,int> d;
    que.push(pii(num,0));
    d[num] = 0;
    while(!que.empty()){
        num = que.top().first;
        int dist = -que.top().second;
        que.pop();
        if(dist > d[num]) continue;
        vi tmp(n);
        rep(i,n)repi(j,i+1,n){
            itov(num,tmp);
            swap(tmp[i],tmp[j]);
            int t = vtoi(tmp);
            int cst = cost[tmp[i]][tmp[j]];
            map<int,int>::iterator itr = d.find(t);
            if(itr == d.end() || (*itr).second > dist + cst){
                d[t] = dist + cst;
                que.push(pii(t,-dist-cst));
            }
        }
    }
    int ans = 0;
    repit(itr,d) ans = max(ans,(*itr).second);
    cout << ans << endl;
    return 0;
}
