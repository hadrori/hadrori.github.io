#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define INF 1e8
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n;

struct B{
    int r, w;
    B(int r, int w):r(r),w(w){}
    bool operator < (const B &b) const{
        return r < b.r;
    }
};

int solve(){
    vector<B> book;
    int sumr = 0, sumw = 0;
    rep(i,n){
        int r, w;
        cin >> r >> w;
        sumr += r; sumw += w;
        book.pb(B(r,w));
    }
    sort(rall(book));
    if(n == 1) return 2 * book[0].r + sumw;

    if(book[0].r*2 <= sumr){
        return sumr + sumw;
    }
    
    int rest = book[0].r*2 - sumr;
    bool dp[1024] = {false};
    dp[0] = true;
    repd(i,n-1,1){
        repd(j,1023,book[i].w) dp[j] |= dp[j-book[i].w];
    }
    repd(i,rest,0) if(dp[i]) return book[0].r*2 + sumw  - i; 
}

int main(){
    while(cin >> n, n){
        cout << solve() << endl;
    }
}
