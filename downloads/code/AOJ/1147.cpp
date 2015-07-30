#include <iostream>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int maxa = 0;
        int mina = 2000;
        int sum = 0;
        rep(z,n){
            int t = 0;
            cin >> t;
            sum += t;
            maxa = max(maxa,t);
            mina = min(mina,t);
        }
        cout << (sum - maxa - mina) / (n - 2) << endl;
    }
}