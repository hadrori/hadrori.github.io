#include <bits/stdc++.h>
#define rep(i, b) for(int i = 0; i < b; i++)
using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        n = 1000 - n;
        int ans = 0;
        int c[6] = {500,100,50,10,5,1};
        rep(i,6){
            while(n/c[i]){
                ans++;
                n -= c[i];
            }
        }
        cout << ans << endl;
    }
}
