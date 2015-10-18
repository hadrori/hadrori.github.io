#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
 
const int N = 1000001;
long long farey[N];
bool p[N];
int n;
vector<int> fc[N];
 
long long solve() {
    return farey[n];
}
 
void prepare() {
    p[0] = p[1] = 1;
    rep(i,N) if(!p[i]) {
        fc[i].push_back(i);
        for (int j = i+i; j < N; j+=i) {
            p[j] = 1;
            fc[j].push_back(i);
        }
    }
 
    farey[0] = 1;
    repi(i,1,N) {
        long long num = 1, den = 1;
        for(auto &e: fc[i]) { den *= e; num *= e-1; }
        farey[i] = farey[i-1]+i/den*num;
    }
}
 
void input() {
    cin >> n;
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    int t; cin >> t;
    prepare();
    while(t--) {
        input();
        cout << solve() << endl;
    }
    return 0;
}