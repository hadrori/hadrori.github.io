#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define rep(i, b) for(int i = 0; i < b; i++)

#define pb push_back
#define mp make_pair

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector<pair<double,string> > rank;
        rep(i,n){
            string l;
            double p, a, b, c, d, e, f, s, m;
            cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;
            double eff = -(s * f * m - p) / (a + b + c + (d + e) * m);
            
            rank.pb(mp(eff,l));
        }
        sort(rank.begin(),rank.end());
        
        rep(i,n){
            cout << rank[i].second << endl;
        }
        cout << '#' << endl;
    }
}