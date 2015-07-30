#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long double eps, d;
int L, num;

inline long double sq(long double x){return x*x;}

int main(){
    cin >> L >> num;
    int ans = 0;
    eps = 1.0;
    d = num;
    for(int i = 0; i < L; i++){
        d /= 10;
        eps /= 10.0;
    }
    while(1){
        long long lb = ceil(sq(d+ans)), ub = sq(d+ans+eps)-1e-9;
        if(lb == ub){
            cout << lb << endl;
            break;
        }
        ans++;
    }
    return 0;
}
