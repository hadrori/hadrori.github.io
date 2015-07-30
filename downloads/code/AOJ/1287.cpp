#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
const int inf = 1e9;
typedef pair<int,int> pii;
int N, M, seq[16][4];
int a, b, d, cnt;
bool used[16];

void solve(){
    vector<pii> tims;
    rep(i,N){
        sort(seq[i], seq[i]+3);
        do{
            int s, m, h;
            rep(j, 60){
                s = (seq[i][0]-j+60)%60;
                m = (seq[i][1]-j+60)%60;
                h = (seq[i][2]-j+60)%60;
                if(h%5 != m/12) continue;
                h /= 5;
                tims.pb(pii(h*3600+m*60+s, i));
            }
        } while(next_permutation(seq[i],seq[i]+3));
    }
    M = tims.size();
    sort(all(tims));
    d = inf;
    rep(i,M){
        cnt = 1;
        memset(used, 0, sizeof(used));
        used[tims[i].second] = 1;
        int s = tims[i].first;
        rep(j,M-1){
            int id = tims[(i+j+1)%M].second, t = tims[(i+j+1)%M].first;
            if(!used[id]){
                used[id] = 1;
                cnt++;
            }
            if(cnt == N){
                int dif = (t-s+43200)%43200;
                if(dif < d) { a = s; b = t; d = dif;}
                break;
            }
        }
    }
    printf("%02d:%02d:%02d %02d:%02d:%02d\n", a/3600, a/60%60, a%60, b/3600, b/60%60, b%60);
}

bool input(){
    cin >> N;
    if(!N) return 0;
    rep(i,N) rep(j,3)
        cin >> seq[i][j];
    return 1;
}
signed main(){
    while(input()) solve();
    return 0;
}


