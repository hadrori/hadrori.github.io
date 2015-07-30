#include <iostream>
#include <vector>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

int main(){
    int n;
    int p;
    while(cin >> n >> p, n){
        vector<int> cand(n);
        int t = p;
        rep(i,n) cand[i] = 0;
        int turn = 0;
        int ans;
        while(1){
            if(t > 0){
                cand[turn%n]++;
                t--;
                if(cand[turn%n] == p){
                    ans = turn % n;
                    break;
                }
            }else {
                t = cand[turn%n];
                cand[turn%n] = 0;
            }
            turn++;
        }
        cout << ans << endl;
    }
}