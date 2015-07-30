#include <algorithm>
#include <iostream>

#define rep(i,a) for(int i = 0;i < (a); i++)

using namespace std;

struct S{
    double val;
    int id;
    S(){}
    S(double val, int id):val(val),id(id){}
    bool operator < (const S &s) const{ return val < s.val;}
};

int n, k;
int v[100010], w[100010];
S u[100010];


bool can(double s){
    rep(i,n) u[i] = S(v[i] - s * w[i],i+1);
    sort(u,u + n);
    double sum = 0;
    rep(i,k) sum += u[n - i - 1].val;
    return sum >= 0;
}

int main(){
    cin >> n >> k;
    rep(i,n) scanf("%d %d", v+i, w+i);
    double lb = 0, ub = 10000000;
    rep(i,50){
        double mid = (lb + ub) / 2;
        if(can(mid)) lb = mid;
        else ub = mid;
    }
    rep(i,k) cout << u[n - i - 1].id << (i==k-1? '\n': ' ');
    return 0;
}
