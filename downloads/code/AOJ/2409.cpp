#include <bits/stdc++.h>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define all(u) (u).begin(),(u).end()
using namespace std;
typedef pair<int,int> pii;

int N, M;
vector<pii> inter;

int main(){
    cin >> N >> M;
    inter.resize(M);
    rep(i,M) cin >> inter[i].first >> inter[i].second;
    sort(all(inter));
    int right = 0, cur = 0;
    int cnt = 0;
    bool used[128] = {false};
    while(true){
        if(right == N) {
            cout << cnt << endl;
            return 0;
        }
        
        int use = -1;
        while(cur < inter.size() && inter[cur].first <= right + 1){
            if(use < inter[cur].second) use = inter[cur].second;
            cur++;
        }
        if(use == -1) break;
        right = use;
        cnt++;
    }
    cout << "Impossible\n";
    return 0;
}
