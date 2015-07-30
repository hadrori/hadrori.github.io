#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
const int di[] = {-1,-1,-1,0,1,1,1,0}, dj[] = {-1,0,1,1,1,0,-1,-1};
int N, st;
map<int,int> d;

inline bool in(int i, int j){ return i >= 0 and i < N and j >=0 and j < N;}

int next_s(int s, int t){
    int ns = 0;
    rep(i,N)rep(j,N)if(i*N+j!=t){
        int cnt = 0;
        rep(dd,8){
            int ni = i+di[dd], nj = j+dj[dd];
            cnt += in(ni,nj) and ((s&(1<<(ni*N+nj))) or (ni*N+nj==t));
        }
        int c = 1<<(i*N+j), v = s&c;
        if(v and cnt > 1 and cnt < 4) ns |= c;
        else if(!v and cnt == 3) ns |= c;
    }
    return ns;
}

int solve(){
    queue<int> q;
    q.push(st);
    d[st] = 0;
    while(!q.empty()){
        int tmp = q.front(); q.pop();
        int s = tmp & ((1<<(N*N))-1), t = tmp>>(N*N);
        int td = d[tmp];
        if(s==0) return td;
        rep(dd,8){
            int ni = t/N+di[dd], nj = t%N+dj[dd];
            int nt = ni*N+nj, ntt = 1<<nt;
            if(in(ni,nj) and !(s&ntt)){
                int ns = next_s(s,nt) | (nt << (N*N));
                if(d.count(ns)) continue;
                d[ns] = td+1; q.push(ns);
            }
        }
    }
    return -1;
}

bool input(){
    cin >> N;
    st = 0; d.clear();
    rep(i,N){
        string s; cin >> s;
        rep(j,N){
            if(s[j] == '#') st |= 1<<(i*N+j);
            else if(s[j] == '@') st |= (i*N+j)<<(N*N);
        }
    }
    return N;
}
 
int main(){
    while(input()) cout << solve() << endl;
    return 0;
}
