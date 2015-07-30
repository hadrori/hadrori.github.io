#include <bits/stdc++.h>
#define rep(i, b) for(int i = 0; i < b; i++)
using namespace std;

int c[3] = {1000,500,100};

int main(){
    int a, b;
    while(cin >> a >> b, a || b){
        int n = b - a;
        int ans[3] = {0};
        rep(i,3){
            while(n/c[i]){
                n -= c[i];
                ans[i]++;
            }
        }
        cout << ans[2] << ' ' << ans[1] << ' ' << ans[0] << endl;
    }
}
