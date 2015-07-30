#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,a) for(int i = 0; i < a; i++)

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        vector<int> score;
        rep(j,n){
            int sum = 0;
            rep(i,5){
                int t;
                cin >> t;
                sum += t;
            }
            score.push_back(sum);
        }
        sort(score.begin(),score.end());
        cout << score[n-1] << ' ' << score[0] << endl;
        
    }
}
