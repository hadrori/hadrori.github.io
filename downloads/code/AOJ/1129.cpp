#include <iostream>
#include <vector>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int main(){
    int n, r;
    while(cin >> n >> r, n || r){
        
        vector<int> deck(n+1);
        rep(i,n+1)deck[i] = n+1-i;
        
        rep(z,r){
            int p, c;
            cin >> p >> c;
            
            vector<int> tmp(p);
            repi(i, 1, p) tmp[i] = deck[i];
            repi(i, 1, c+1) deck[i] = deck[p+i-1];
            repi(i, c+1, p+c) deck[i] = tmp[i-c];
        }
        cout << deck[1] << endl;
    }
}