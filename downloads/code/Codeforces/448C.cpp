#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)

int n, a[5010];

int rec(int l, int r, int f){
    if(l >= r) return 0;
    int m = l;
    repi(i,l,r) if(a[m] > a[i]) m = i;
    return min(r-l,a[m]-f+rec(l,m,a[m])+rec(m+1,r,a[m]));
}

int main(){
    cin >> n;
    rep(i,n) cin >> a[i];
    cout << rec(0,n+1,0) << endl;
    return 0;
}
