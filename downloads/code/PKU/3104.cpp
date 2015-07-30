#include <iostream>
#define rep(i,a) for(int i = 0;i < (a); i++)
using namespace std;

typedef long long ll;

int n, k;
int a[100010];

bool can(int t){
    ll cnt = 0;
    rep(i,n){
        int res = a[i] - t;
        if(res > 0) cnt += (res + k - 2) / (k - 1);
    }
    return cnt <= t;
}

int main(){
    cin >> n;
    int maxa = 0;
    rep(i,n){
        scanf("%d",a+i);
        if(maxa < a[i]) maxa = a[i];
    }
    cin >> k;
    if(k == 1){
        cout << maxa << endl;
        return 0;
    }
    int lb = 0, ub = 1000000100;
    while(lb + 1 < ub){
        int mid = (lb + ub) / 2;
        if(can(mid)) ub = mid;
        else lb = mid;
    }
    cout << ub << endl;
    return 0;
}
