#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define rep(i,a) for(int i = 0; i < a; i++)
#define repi(i,a,b) for(int i = a; i < b; i++)
#define repd(i,a,b) for(int i = a; i > b; i--)

#define pb push_back


using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int> > game(n,vector<int>(3));
    rep(j,n)rep(i,3){
        cin >> game[j][i];
    }
    vector<int> score(n,0);
    rep(i,3) {
        vector<bool> man(n,true);
        rep(j,n){
            if(man[j]){
                repi(k,j+1,n){
                    if(game[j][i] == game[k][i]){
                        man[j] = false;
                        man[k] = false;
                    }
                }
            }
        }
        rep(j,n){
            if(man[j]) score[j] += game[j][i];
        }
    }
    rep(i,n) cout << score[i] << endl;
}
