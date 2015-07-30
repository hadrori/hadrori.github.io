#include <iostream>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)

int N;
double A, B;
double H[1024];

bool ok(double h){
    H[1] = h;
    repi(i,2,N){
	H[i] = 2*H[i-1] + 2 - H[i-2];
	if(H[i] < 0) return false;
    }
    B = H[N-1];
    return true;
}

int main(){
    cin >> N >> A;
    H[0] = A;
    double lb = -1, ub = 1000000;
    rep(_,100){
        double mid = (lb + ub) / 2;
        if(ok(mid)) ub = mid;
        else lb = mid;
    }
    printf("%.2f\n", B);
    return 0;
}
