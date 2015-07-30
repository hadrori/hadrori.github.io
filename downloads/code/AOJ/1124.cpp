#include <iostream>
#include <vector>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

int main(){
    int n, q;
    while(cin >> n >> q, n || q){
        vector<int> sch(101,0);
        rep(i, n){
            int m;
            cin >> m;
            rep(j, m){
                int d;
                cin >> d;
                sch[d]++;
            }
        }
        int ans;
        int maxa = 0;
        rep(i,101){
            if(sch[i] > maxa){
                ans = i;
                maxa = sch[i];
            }
        }
        if(maxa >= q)cout << ans << endl;
        else cout << 0 << endl;
    }
}