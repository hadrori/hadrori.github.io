#include <iostream>

#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

using namespace std;

ll n;

int main(){
    cin >> n;
    int cnt = 0;
    while(n > 1){
        if(n % 3 != 0){
            n /= 3;
            n++;
        }else{
            n /= 3;
        }
        cnt++;
    }
    cout << cnt << endl;
}