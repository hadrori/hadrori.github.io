#include <bits/stdc++.h>

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) (u).begin(),(u).end()
using namespace std;
typedef vector<int> vi;

int n, d;

int main(){
    while(cin >> n >> d, n || d){
        vector<vi> missiles(n);
        vi cap(n,0);
        rep(i,n){
            int m, c;
            cin >> m;
            missiles[i].resize(m);
            rep(j,m){
                cin >> missiles[i][j];
                cap[i] += missiles[i][j];
            }
        }
        while(true){
            bool erased = false;
            rep(i,n)if(missiles[i].size()){
                while(missiles[i].size()){
                    cap[i] -= missiles[i].back();
                    if(*max_element(all(cap)) - cap[i] <= d){
                        missiles[i].pop_back();
                        erased = true;
                    }
                    else {
                        cap[i] += missiles[i].back();
                        break;
                    }
                }
            }
            if(!erased) break;
        }
        bool ok = true;
        rep(i,n) if(missiles[i].size()) ok = false;
        cout << (ok? "Yes": "No") << endl;
    }
    return 0;
}
