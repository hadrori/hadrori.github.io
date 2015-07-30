#include <bits/stdc++.h>
#define rep(i, b) for(int i = 0; i < b; i++)

#define pb push_back
#define mp make_pair

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector<pair<int,string> > pr;
        rep(i,n){
            string na;
            int w, s;
            cin >> na >> w >> s;
            int t = w*24*60 + s%100 + s/100 * 60;;
            pr.pb(mp(t,na));
        }
        sort(pr.begin(),pr.end());
        int p;
        cin >> p;
        vector<string> fav(p);
        int ans = 0;
        rep(i,p){
            bool flag = true;
            cin >> fav[i];
            rep(j,pr.size()) if(fav[i] == pr[j].second){
                flag = false;
                ans++;
                int t = pr[j].first;
                rep(k,pr.size()){
                    if(pr[k].first > t-30 && pr[k].first < t+30){
                        pr.erase(pr.begin()+k,pr.begin()+k+1);
                        k--;
                    }
                }
            }
            if(flag) ans = -1000;
        }
        int tail = 0;
        rep(i,pr.size()){
            if(tail <= pr[i].first){
                ans++;
                tail = pr[i].first + 30;
            }
        }
        if(ans<0) cout << -1 << endl;
        else cout << ans << endl;
    }
}
