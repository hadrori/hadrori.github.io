#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define INF 1e8
typedef vector<int> vi;

int main(){
    int n, m, s, g1, g2;
    while(cin >> n >> m >> s >> g1 >> g2, n||m||s||g1||g2){
        s--; g1--; g2--;
        vector<vi> c(n,vi(n,INF));
        rep(i,m){
            int b1, b2, c1;
            cin >> b1 >> b2 >> c1;
            c[--b1][--b2] = c1;
        }
        rep(i,n) c[i][i] = 0;
        rep(k,n) rep(i,n) rep(j,n){
            c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
        }
        int ans = INF;
        rep(i,n){
            ans = min(ans, c[s][i] + c[i][g1] + c[i][g2]);
        }
        cout << ans << endl;
    }
}
