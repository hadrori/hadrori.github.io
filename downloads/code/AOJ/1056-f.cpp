#include <iostream>
#include <cstdio>

#define rep(i,a) for(int i = 0; i < a; i++)
#define repi(i,a,b) for(int i = a; i < b; i++)
#define repd(i,a,b) for(int i = a; i > b; i--)

#define pb push_back
#define mp make_pair

using namespace std;

long long fib[100001];
double ans[100001];
long long fibs[100001];

int main(){
    
    fib[0] = 1;
    fib[1] = 0;
    fibs[0] = 1;
    fibs[1] = 1;
    repi(i,1,100001){
        if(i > 1){
            fib[i] = fib[i-1] + fib[i-2];
            fibs[i] = fibs[i-1] + fib[i];
            //if(i > 15) fibs[i] -= fibs[i-15];
        }
        double sum = 0;
        rep(j,i){
            if(j > 50) break;
            sum += (double)fib[i-j-1] / (1 << j);
        }
        ans[i] = ans[i-1] + sum / fibs[i-1];
    }
    int n;
    while(cin >> n, n){
        printf("%.8f\n", ans[n]);
    }
}
