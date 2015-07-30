#include <iostream>

#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;
int t;
int x, y, w, h;
int n;

int main(){
    cin >> t;
    
    rep(z, 0, t){
        cin >> x >> y >> w >> h;
        cin >> n;
        
        int cnt = 0;
        rep(i, 0, n){
            int tx, ty;
            cin >> tx >> ty;
            if((tx >= x) && (tx <= x + w) && (ty >= y) && (ty <= y + h)) cnt++;
        }
        cout << cnt << endl;
    }
    
}