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

int h, w, c;
int p[10][10];
int tp[10][10];
int e[4];
int c1, c2;

int chng(int x, int y){
    tp[x][y] = c2;
    int cnt = 1;
    
    if(x > 0 && tp[x-1][y] == c1) cnt += chng(x-1,y);
    if(x < h-1 && tp[x+1][y] == c1) cnt += chng(x+1,y);
    if(y > 0 && tp[x][y-1] == c1) cnt += chng(x,y-1);
    if(y < w-1 && tp[x][y+1] == c1) cnt += chng(x,y+1);
    
    return cnt;
}

int eshock(){
    
    rep(i,h)rep(j,w) tp[i][j] = p[i][j];

    rep(i,4){
        c1 = tp[0][0];
        c2 = e[i];
        if(c1 != c2)chng(0,0);
    }
    
    c1 = tp[0][0];
    c2 = c;
    if(c1 != c2) chng(0,0);
    c1 = c;
    c2 = (c<5)? c+1: 0;
    return chng(0,0);
}


int main(){
    while(cin >> h >> w >> c, h || w || c){
        c--;
        rep(i,h)rep(j,w){
            int t;
            cin >> t;
            p[i][j] = --t;
        }
        //cout << h << w << c << endl;
        int maxa = 0;
        for(e[0] = 0; e[0] < 6; e[0]++){
            for(e[1] = 0; e[1] < 6; e[1]++){
                for(e[2] = 0; e[2] < 6; e[2]++){
                    for(e[3] = 0; e[3] < 6; e[3]++){
                        maxa = max(maxa, eshock());
                        //cout << e[2] << ' ' << e[3] << endl;
                    }
                }
            }
        }
        cout << maxa << endl;
    }
}