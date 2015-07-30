#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

using namespace std;

ll t, n, k;

int main(){
    cin >> t;
    
    rep(z, 0, t){
        cin >> n >> k;
        
        vector<int> house(n);
        rep(i, 0, n) cin >> house[i];
        
        vector<int> dis;
        rep(i, 1, n) {
            dis.push_back(house[i] - house[i-1]);
        }
        ll sum = house[n-1] - house[0];
        sort(dis.rbegin(),dis.rend());
        
        if(n <= k) sum = 0;
        else rep(i, 0, k-1) sum -= dis[i];
        
        cout << sum << endl;
        
    }
    
}