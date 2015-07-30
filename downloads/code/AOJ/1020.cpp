#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <bitset>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

typedef long long ll;

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        double rate[3][3][16];
        rep(i,3)rep(j,3)rep(k,16) rate[i][j][k] = 0;
        char s, t, b;
        cin >> s >> t >> b;
        int sx = (s-'A') % 3;
        int sy = (s-'A') / 3;
        int tx = (t-'A') % 3;
        int ty = (t-'A') / 3;
        int bx = (b-'A') % 3;
        int by = (b-'A') / 3;

        rate[sx][sy][0] = 1.0;
        repi(k,1,n+1){
            rep(j,3)rep(i,3){
                if(i>0 && (i-1 != bx || j != by)) rate[i-1][j][k] += rate[i][j][k-1] / 4;
                else rate[i][j][k] += rate[i][j][k-1] / 4;
                if(i<2 && (i+1 != bx || j != by)) rate[i+1][j][k] += rate[i][j][k-1] / 4;
                else rate[i][j][k] += rate[i][j][k-1] / 4;
                if(j>0 && (i != bx || j-1 != by)) rate[i][j-1][k] += rate[i][j][k-1] / 4;
                else rate[i][j][k] += rate[i][j][k-1] / 4;
                if(j<2 && (i != bx || j+1 != by)) rate[i][j+1][k] += rate[i][j][k-1] / 4;
                else rate[i][j][k] += rate[i][j][k-1] / 4;
            }

        }
        printf("%.8f\n",rate[tx][ty][n]);
    }
}
