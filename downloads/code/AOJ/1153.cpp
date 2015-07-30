#include <iostream>
#include <vector>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n || m){
        vector<int> taro(n);
        vector<int> hanako(m);
        int tsum = 0;
        int hsum = 0;
        rep(i,n) {
            cin >> taro[i];
            tsum += taro[i];
        }
        rep(i,m){
            cin >> hanako[i];
            hsum += hanako[i];
        }
        
        int t = 1000;
        int h = 1000;
        rep(i, n){
            tsum -= taro[i];
            rep(j, m){
                hsum -= hanako[j];
                if(tsum + hanako[j] == hsum + taro[i]){
                    if(taro[i] + hanako[j] < t + h){
                        t = taro[i];
                        h = hanako[j];
                    }
                }
                hsum += hanako[j];
            }
            tsum += taro[i];
        }
        if(t == 1000) cout << -1 << endl;
        else cout << t << ' ' << h << endl;
    }
    
}