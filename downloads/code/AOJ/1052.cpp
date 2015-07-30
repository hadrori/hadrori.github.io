#include <bits/stdc++.h>
#define rep(i, b) for(int i = 0; i < b; i++)
#define pb push_back
using namespace std;
typedef pair<int,int> P;

int main(){
    int n;
    while(cin >> n, n){
        vector<P> br;
        rep(i,n){
            int a, b;
            cin >> a >> b;
            br.pb(P(b,a));
        }
        sort(br.begin(),br.end());
        int w = 0;
        rep(i,n){
            if(w + br[i].second <= br[i].first) w += br[i].second;
            else {
                w = -1;
                break;
            }
        }
        if(w==-1) cout << "No\n";
        else cout << "Yes\n";
    }
}
