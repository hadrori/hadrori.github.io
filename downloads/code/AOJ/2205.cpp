#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,a) for(int i = 0; i < a; i++)

#define mp make_pair

using namespace std;

typedef long long ll;

int main(){
    int n, m;
    while(cin >> n >> m, n||m){
        vector<pair<string,ll> > atari(n);
        string kuji;
        ll ans = 0;
        rep(i,n){
            string str;
            ll k;
            cin >> str >> k;
            atari[i] = mp(str,k);
        }
        rep(i,m){
            cin >> kuji;
            rep(j,n){
                bool atatta = true;
                rep(k,8){
                    if(atari[j].first[k] == '*') continue;
                    if(atari[j].first[k] != kuji[k]){
                        atatta = false;
                        break;
                    }
                }
                if(atatta) ans += atari[j].second;
            }
        }
        cout << ans << endl;
    }
}
