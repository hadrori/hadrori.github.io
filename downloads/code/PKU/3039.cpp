#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

const int M = 32767;

int num, den, anum, aden;
double diff;

int main(){
    scanf("%d%d", &num, &den);
    diff = 1e9;
    
    for(int d = 2; d <= M; d++){
        if(d == den) continue;
        int nn = num * d / den;
        for(int n = max(1, nn-1); n <= min(d-1, nn+1); n++){
            if(__gcd(n, d) > 1) continue;
            double di = abs(1. * num / den - 1. * n / d);
            if(di < diff) {
                diff = di;
                anum = n;
                aden = d;
            }
        }
    }
    printf("%d %d\n", anum, aden);
    return 0;
}
