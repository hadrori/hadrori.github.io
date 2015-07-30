#include <iostream>
#include <vector>

const int INF = 1e9;
#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m, n || m){
        int w[128][128][2];
        rep(i,m+1)rep(j,m+1)rep(k,2) w[i][j][k] = INF;
        
        rep(i,n){
            int a, b, c, t;
            cin >> a >> b >> c >> t;
            w[a][b][0] = c;
            w[b][a][0] = c;
            w[a][b][1] = t;
            w[b][a][1] = t;
        }
        rep(l,2) repi(k, 1, m+1) repi(i, 1, m+1) repi(j, 1, m+1)
            w[i][j][l] = min(w[i][j][l], w[i][k][l] + w[k][j][l]);

        int k;
        cin >> k;
        
        rep(i,k){
            int p, q, r;
            cin >> p >> q >> r;            
            cout << w[p][q][r] << endl;
        }
    }
}
