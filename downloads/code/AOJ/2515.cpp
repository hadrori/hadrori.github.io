#include <bits/stdc++.h>
#define rep(i,a) for(int i = 0;i < (a); i++)
#define pb push_back
#define mp make_pair

using namespace std;

int main(){
    int N, T;
    cin >> N >> T;
    vector<pair<string, int> > ans;
    int prev = INF;
    int sh, sm, ah, am;
    string sn, an;
    while(N--){
        scanf("%d:%d",&sh,&sm);
        cin >> sn;
        scanf("%d:%d",&ah,&am);
        cin >> an;
        int m = sh * 60 + sm;
        if(m - prev >= T)ans.pb(mp(sn,m-prev));
        prev = ah * 60 + am;
    }
    cout << ans.size() << endl;
    rep(i,ans.size())
        cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}
