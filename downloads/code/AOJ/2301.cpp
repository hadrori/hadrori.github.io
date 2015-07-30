#include <bits/stdc++.h>
using namespace std;

int K;
double R, L, P, E, T;

double dfs(double r, double l, int k){
    if(r > T + E || l < T - E) return 0;
    if(k == K){
        if(abs((r + l) / 2 - T) <= E) return 1;
        return 0;
    }
    if(r >= T - E && l <= T + E) return 1;
    double ret = 0;
    double h = (r + l) / 2;
    if(h >= T) {
        ret += (1 - P) * dfs(r,h,k+1);
        ret += P * dfs(h,l,k+1);
    }
    else {
        ret += P * dfs(r,h,k+1);
        ret += (1 - P) * dfs(h,l,k+1);
    }
    return ret;
}

int main(){
    cin >> K >> R >> L >> P >> E >> T;
    printf("%.6f\n", dfs(R,L,0));
    return 0;
}
