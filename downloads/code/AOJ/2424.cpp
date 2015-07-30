#include <iostream>
#include <algorithm>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

int main(){
    int q;
    cin >> q;
    rep(z, q){
        int n;
        cin >> n;
        
        int t = n;
        int cnt = 0;
        while( t / 10 > 0){
            int d = 10;
            int maxa = 0;
            while( t / d > 0){
                maxa = max(maxa, (t / d) * (t % d));
                d *= 10;
            }
            t = maxa;
            if(t == n) {
                cnt = n;
                break;
            }
            cnt++;
        }
        cout << cnt << endl;
    }
}