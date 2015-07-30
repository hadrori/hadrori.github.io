#include <iostream>

#define rep(i,a) for(int i = 0; i < int(a); i++)

using namespace std;

int m, n;
int choco[128][128];

int main(){
    cin >> m >> n;
    int cnt = 0;
    rep(i,m){
        rep(j,n){
            cin >> choco[i][j];
            if(i) choco[i][j] = 1 - choco[i][j];
        }
        int tmp = 0, l = 0, r = n-1;
        while(l <= r){
            if(choco[i][l]){
                cnt++; l++;
                if(l < n)choco[i][l] = 1 - choco[i][l];
            }
            else{
                cnt += choco[i][r--];
                choco[i][r] = 1 - choco[i][r];
            }
        }
    }
    cout << cnt << endl;
}
