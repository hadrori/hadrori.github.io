#include <iostream>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

int main(){
    int n;
    cin >> n;
    rep(z,n){
        int y, m, d;
        cin >> y >> m >> d;
        
        int rest = (999 - y) * (20 * 5 + 19 * 5) + (999 / 3 - y / 3) * 5;
        
        if(y % 3 == 0) rest += (10 - m) * 20;
        else rest += (10 - m) * 19 + (10 - m) / 2;
        
        if(m % 2 == 0){
            if(y % 3 == 0) rest += 20 - d + 1;
            else rest += 19 - d + 1;
        }else{
            rest += 20 - d + 1;
        }
        
        cout << rest << endl;
    }
}
